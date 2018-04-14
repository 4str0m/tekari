#pragma once

#include <nanogui/common.h>
#include <nanogui/glutil.h>
#include <vector>
#include <memory>
#include <functional>
#include "delaunay.h"
#include "Metadata.h"
#include "ColorMap.h"

struct DataSample
{
    enum Views
    {
        NORMAL = 0,
        LOG,
        PATH,
        POINTS,
        VIEW_COUNT
    };

    enum SelectionMode
    {
        STANDARD,
        ADD,
        SUBTRACT
    };

public:
    DataSample();
    DataSample(const std::string& sampleDataPath);
    DataSample(const DataSample&) = delete;
    DataSample(DataSample&&) = default;

    ~DataSample();

    DataSample& operator=(const DataSample&) = delete;
    DataSample& operator=(DataSample&&) = default;

    void drawGL(const nanogui::Vector3f& viewOrigin,
                const nanogui::Matrix4f& model,
                const nanogui::Matrix4f& view,
                const nanogui::Matrix4f& proj,
                bool useShadows,
                std::shared_ptr<ColorMap> colorMap);

    void toggleView(Views view, bool toggle) { m_DisplayViews[view] = toggle; }
    bool displayView(Views view) const { return m_DisplayViews[view]; }

    void loadFromFile(const std::string& sampleDataPath);
    void linkDataToShaders();

    std::string name()          const { return m_Metadata.sampleName; }
    unsigned int pointsCount()  const { return tri_delaunay2d->num_points; }
    float minHeight()           const { return m_MinMaxHeights.first; }
    float maxHeight()           const { return m_MinMaxHeights.second; }
    float averageHeight()       const { return m_AverageHeight; }

    const Metadata& metadata() const { return m_Metadata; }

    void selectPoints(const nanogui::Matrix4f& mvp,
        const nanogui::Vector2i& topLeft,
        const nanogui::Vector2i& size,
        const nanogui::Vector2i & canvasSize,
        SelectionMode mode);
    void deselectAllPoints();

private:
    inline nanogui::Vector3f getVertex(unsigned int i, bool logged) const;
    void computeTriangleNormal(unsigned int i0, unsigned int i1, unsigned int i2, bool logged);

    void readDataset(const std::string &filePath, std::vector<del_point2d_t> &points);
    void computeNormals();

private:
    // Raw sample data
    tri_delaunay2d_t *tri_delaunay2d;
    std::vector<float>				m_Heights;
    std::vector<float>              m_LogHeights;
    std::vector<nanogui::Vector3f>  m_Normals;
    std::vector<nanogui::Vector3f>  m_LogNormals;
    std::pair<float, float>         m_MinMaxHeights;
    float                           m_AverageHeight;

    // display Shaders
    nanogui::GLShader m_Shaders[VIEW_COUNT];
    std::function<void(Views, const nanogui::Vector3f&, const nanogui::Matrix4f&, const nanogui::Matrix4f&,
        const nanogui::Matrix4f&, const nanogui::Matrix4f, bool, std::shared_ptr<ColorMap>)> m_DrawFunctions[VIEW_COUNT];
    std::vector<unsigned int> m_PathSegments;

    // display options
    bool m_DisplayViews[VIEW_COUNT];

    // metadata
    Metadata m_Metadata;

    // Selected point
    std::vector<char> m_SelectedPoints;
    float             m_SelectedPointsAverageHeight;
};