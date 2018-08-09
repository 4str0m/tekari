#include <tekari/points_stats.h>

#include <limits>
#include <iostream>
#include <tekari/selections.h>

TEKARI_NAMESPACE_BEGIN

PointsStats::PointsStats()
: intensity_count(0)
, points_count(0)
{}

void PointsStats::reset(size_t i_count)
{
    intensity_count = i_count;
    points_count = 0;
    m_slices.assign(i_count, Slice());
}

inline void points_stats_add_intensity(PointsStats::Slice& point_stats, float intensity, size_t index)
{
    if (intensity < point_stats.min_intensity)
    {
        point_stats.lowest_point_index = index;
        point_stats.min_intensity = intensity;
    }
    if (intensity > point_stats.max_intensity)
    {
        point_stats.highest_point_index = index;
        point_stats.max_intensity = intensity;
    }
}

void update_selection_stats(
    PointsStats& selection_stats,
    const VectorXf& selected_points,
    const RawMeasurement& raw_measurement,
    const Matrix2Xf& V2D,
    const MatrixXXf& H,
    const MatrixXXf& LH,
    size_t intensity_index
)
{
    cout << std::setw(50) << std::left << "Updating selection statistics .. ";
    Timer<> timer;

    PointsStats::Slice& slice = selection_stats[intensity_index];

    for (Index i = 0; i < selected_points.size(); ++i)
    {
        if (SELECTED(selected_points[i]))
        {
            ++selection_stats.points_count;

            points_stats_add_intensity(slice, raw_measurement[i][intensity_index+2], i);
            slice.average_intensity  += raw_measurement[i][intensity_index];
            slice.average_point      += get_3d_point(V2D, H[intensity_index], i);
            slice.average_log_point  += get_3d_point(V2D, LH[intensity_index], i);
        }
    }
    if (selection_stats.points_count > 1)
    {
        float scale = 1.0f / selection_stats.points_count;
        slice.average_intensity *= scale;
        slice.average_point *= scale;
        slice.average_log_point *= scale;
    }
    
    cout << "done. (took " <<  time_string(timer.value()) << ")" << endl;
}

void compute_min_max_intensities(
    PointsStats& points_stats,
    const RawMeasurement& raw_measurement,
    size_t intensity_index
)
{
    cout << std::setw(50) << std::left << "Computing minimum/maximum intensities .. ";
    Timer<> timer;

    for (Index i = 0; i < raw_measurement.n_sample_points(); ++i)
        points_stats_add_intensity(points_stats[intensity_index], raw_measurement[i][intensity_index+2], i);

    Log(Error, "min = %f, max = %f\n", points_stats[intensity_index].min_intensity, points_stats[intensity_index].max_intensity);

    cout << "done. (took " <<  time_string(timer.value()) << ")" << endl;
}

void update_points_stats(
    PointsStats& points_stats,
    const RawMeasurement& raw_measurement,
    const Matrix2Xf& V2D,
    const MatrixXXf& H,
    const MatrixXXf& LH,
    size_t intensity_index
)
{
    cout << std::setw(50) << std::left << "Updating points statistics .. ";
    Timer<> timer;

    PointsStats::Slice& slice = points_stats[intensity_index];

    points_stats.points_count = raw_measurement.n_sample_points();
    for (Index i = 0; i < raw_measurement.n_sample_points(); ++i)
    {
        slice.average_intensity += raw_measurement[i][intensity_index];
        slice.average_point += get_3d_point(V2D, H[intensity_index], i);
        slice.average_log_point += get_3d_point(V2D, LH[intensity_index], i);
    }
    if (points_stats.points_count != 0)
    {
        float scale = 1.0f / points_stats.points_count;
        slice.average_intensity *= scale;
        slice.average_point *= scale;
        slice.average_log_point *= scale;
    }

    cout << "done. (took " <<  time_string(timer.value()) << ")" << endl;
}

TEKARI_NAMESPACE_END