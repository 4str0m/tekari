#pragma once

#if defined(_WIN32)
#    if defined(APIENTRY)
#        undef APIENTRY
#    endif
#    define NOMINMAX  // Remove min/max macros when building on windows
#    include <Windows.h>
#    undef NOMINMAX
#    undef near      // also cleanup some macros conflicting with variable names
#    undef far
#    pragma warning(disable : 4127) // warning C4127: conditional expression is constant
#    pragma warning(disable : 4244) // warning C4244: conversion from X to Y, possible loss of data
#    pragma warning(disable : 4251) // warning C4251: class X needs to have dll-interface to be used by clients of class Y
#    pragma warning(disable : 4714) // warning C4714: function X marked as __forceinline not inlined
#endif

#include <algorithm>
#include <cctype>
#include <string>
#include <utility>
#include <functional>
#include <memory>
#include <nanogui/glutil.h>
#include <array>
#include <enoki/array.h>
#include <enoki/matrix.h>

// (re)define M_PI locally since it's not necessarily defined on some platforms
#undef M_PI
#define M_PI 3.141592653589793238463

#define ENABLE_PROFILING

// Define command key for windows/mac/linux
#if defined(__APPLE__) || defined(DOXYGEN_DOCUMENTATION_BUILD)
    /// If on OSX, maps to ``GLFW_MOD_SUPER``.  Otherwise, maps to ``GLFW_MOD_CONTROL``.
    #define SYSTEM_COMMAND_MOD GLFW_MOD_SUPER
#else
    #define SYSTEM_COMMAND_MOD GLFW_MOD_CONTROL
#endif

#define TEKARI_NAMESPACE_BEGIN namespace tekari {
#define TEKARI_NAMESPACE_END }

#define GRAIN_SIZE 1024u

TEKARI_NAMESPACE_BEGIN

// ============== Extract useful types from namespaces ===========

// common types from std
using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::shared_ptr;
using std::pair;
using std::function;

// useful std functions
using std::make_pair;
using std::make_shared;
using std::to_string;

// usefull types from nanogui
using nanogui::Color;
using nanogui::Vector2f;
using nanogui::Vector3f;
using nanogui::Vector4f;
using nanogui::Vector2i;
using nanogui::Matrix4f;
using nanogui::Quaternion4f;

// custom types
using Vector3u = std::array<uint32_t, 3>; // cannot use enoki arrays because it messes up opengl indices
using Matrix3f = enoki::Matrix<float, 3>;
using Matrix2Xf = vector<Vector2f>;
using Matrix3Xf = vector<Vector3f>;
using Matrix4Xf = vector<Vector4f>;
using MatrixXXf = vector<vector<float>>;
using Matrix3Xu = vector<Vector3u>;
using VectorXu  = vector<uint32_t>;
using VectorXi8 = vector<int8_t>;
using VectorXf  = vector<float>;

using Index = size_t;


// ============= 3D Utils =============

inline Vector4f project_on_screen(const Vector3f& point,
    const Vector2i& canvas_size,
    const Matrix4f& mvp)
{
    Vector4f projected_point( mvp* concat(point, 1.0f) );

    projected_point /= projected_point[3];
    projected_point[0] = (projected_point[0] + 1.0f)* 0.5f* canvas_size.x();
    projected_point[1] = canvas_size.y() - (projected_point[1] + 1.0f)* 0.5f* canvas_size.y();
    return projected_point;
}

inline Vector3f get3DPoint(const Matrix2Xf& V2D, const VectorXf& H, unsigned int index)
{
    return Vector3f( V2D[index][0], H[index], V2D[index][1] );
}

inline Matrix4Xf get3DPoints(const Matrix2Xf& V2D, const vector<VectorXf>& H, unsigned int index)
{
    Matrix4Xf result;
    result.resize(H.size()) ;
    for (size_t i = 0; i < H.size(); i++)
    {
        result[i] = get3DPoint(V2D, H[i], index);
    }
    return result;
}

inline Vector2f transform_raw_point(const Vector2f& raw2DPoint)
{

    return Vector2f(   (float)(raw2DPoint[0]* cos(raw2DPoint[1]* M_PI / 180.0f) / 90.0f),
                       (float)(raw2DPoint[0]* sin(raw2DPoint[1]* M_PI / 180.0f) / 90.0f) );
}


// ================= String Utils ================

// trim from start (in place)
inline void ltrim(string &s, function<int(int)> pred = [](int c) { return std::isspace(c); }) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [pred](int ch) {
        return !pred(ch);
    }));
}

// trim from end (in place)
inline void rtrim(string &s, function<int(int)> pred = [](int c) { return std::isspace(c); }) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [pred](int ch) {
        return !pred(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
inline void trim(string &s, function<int(int)> pred = [](int c) { return std::isspace(c); }) {
    ltrim(s, pred);
    rtrim(s, pred);
}

// trim from start (copying)
inline string ltrim_copy(string s, function<int(int)> pred = [](int c) { return std::isspace(c); }) {
    ltrim(s, pred);
    return s;
}

// trim from end (copying)
inline string rtrim_copy(string s, function<int(int)> pred = [](int c) { return std::isspace(c); }) {
    rtrim(s, pred);
    return s;
}

// trim from both ends (copying)
inline string trim_copy(string s, function<int(int)> pred = [](int c) { return std::isspace(c); }) {
    trim(s, pred);
    return s;
}

TEKARI_NAMESPACE_END