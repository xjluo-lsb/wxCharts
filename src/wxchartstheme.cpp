/*
    Copyright (c) 2017-2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

/// @file

#include "wxchartstheme.h"
#include "wxchartspresentationtheme.h"

wxChartsTheme::wxChartsTheme()
    : m_areaChartOptions(new wxAreaChartOptions()),
    m_barChartOptions(new wxBarChartOptions()),
    m_boxPlotOptions(new wxBoxPlotOptions()),
    m_bubbleChartOptions(new wxBubbleChartOptions()),
    m_candlestickChartOptions(new wxCandlestickChartOptions()),
    m_columnChartOptions(new wxColumnChartOptions()),
    m_doughnutChartOptions(new wxDoughnutChartOptions()),
    m_histogramOptions(new wxHistogramOptions()),
    m_lineChartOptions(new wxLineChartOptions()),
    m_math2DPlotOptions(new wxMath2DPlotOptions()),
    m_ohlcChartOptions(new wxOHLCChartOptions()),
    m_pieChartOptions(new wxPieChartOptions()),
    m_polarAreaChartOptions(new wxPolarAreaChartOptions()),
    m_radarChartOptions(new wxRadarChartOptions()),
    m_scatterPlotOptions(new wxScatterPlotOptions()),
    m_stackedBarChartOptions(new wxStackedBarChartOptions()),
    m_stackedColumnChartOptions(new wxStackedColumnChartOptions()),
    m_timeSeriesChartOptions(new wxTimeSeriesChartOptions())
{
}

wxAreaChartOptions::ptr wxChartsTheme::GetAreaChartOptions()
{
    return m_areaChartOptions;
}

wxBarChartOptions::ptr wxChartsTheme::GetBarChartOptions()
{
    return m_barChartOptions;
}

wxBoxPlotOptions::ptr wxChartsTheme::GetBoxPlotOptions()
{
    return m_boxPlotOptions;
}

wxBubbleChartOptions::ptr wxChartsTheme::GetBubbleChartOptions()
{
    return m_bubbleChartOptions;
}

wxCandlestickChartOptions::ptr wxChartsTheme::GetCandlestickChartOptions()
{
    return m_candlestickChartOptions;
}

wxColumnChartOptions::ptr wxChartsTheme::GetColumnChartOptions()
{
    return m_columnChartOptions;
}

wxDoughnutChartOptions::ptr wxChartsTheme::GetDoughnutChartOptions()
{
    return m_doughnutChartOptions;
}

wxHistogramOptions::ptr wxChartsTheme::GetHistogramOptions()
{
    return m_histogramOptions;
}

wxLineChartOptions::ptr wxChartsTheme::GetLineChartOptions()
{
    return m_lineChartOptions;
}

wxMath2DPlotOptions::ptr wxChartsTheme::GetMath2DPlotOptions()
{
    return m_math2DPlotOptions;
}

wxOHLCChartOptions::ptr wxChartsTheme::GetOHLCChartOptions()
{
    return m_ohlcChartOptions;
}

wxPieChartOptions::ptr wxChartsTheme::GetPieChartOptions()
{
    return m_pieChartOptions;
}

wxPolarAreaChartOptions::ptr wxChartsTheme::GetPolarAreaChartOptions()
{
    return m_polarAreaChartOptions;
}

wxRadarChartOptions::ptr wxChartsTheme::GetRadarChartOptions()
{
    return m_radarChartOptions;
}

wxScatterPlotOptions::ptr wxChartsTheme::GetScatterPlotOptions()
{
    return m_scatterPlotOptions;
}

wxStackedBarChartOptions::ptr wxChartsTheme::GetStackedBarChartOptions()
{
    return m_stackedBarChartOptions;
}

wxStackedColumnChartOptions::ptr wxChartsTheme::GetStackedColumnChartOptions()
{
    return m_stackedColumnChartOptions;
}

wxTimeSeriesChartOptions::ptr wxChartsTheme::GetTimeSeriesChartOptions()
{
    return m_timeSeriesChartOptions;
}

wxSharedPtr<wxChartsDatasetTheme> wxChartsTheme::GetDatasetTheme(const wxChartsDatasetId& id)
{
    return m_datasetThemes[id];
}

void wxChartsTheme::SetDatasetTheme(const wxChartsDatasetId& id, wxSharedPtr<wxChartsDatasetTheme> theme)
{
    m_datasetThemes[id] = theme;
}

// By default the default theme is actually the wxChartsPresentationTheme
wxSharedPtr<wxChartsTheme> wxChartsDefaultTheme(new wxChartsPresentationTheme());
