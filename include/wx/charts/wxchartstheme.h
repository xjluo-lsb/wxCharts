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

#ifndef _WX_CHARTS_WXCHARTSTHEME_H_
#define _WX_CHARTS_WXCHARTSTHEME_H_

#include "wxcharts_export.h"

#include "wxareachartoptions.h"
#include "wxbarchartoptions.h"
#include "wxboxplotoptions.h"
#include "wxbubblechartoptions.h"
#include "wxcandlestickchartoptions.h"
#include "wxcolumnchartoptions.h"
#include "wxdoughnutchartoptions.h"
#include "wxhistogramoptions.h"
#include "wxlinechartoptions.h"
#include "wxmath2dplotoptions.h"
#include "wxohlcchartoptions.h"
#include "wxpiechartoptions.h"
#include "wxpolarareachartoptions.h"
#include "wxradarchartoptions.h"
#include "wxscatterplotoptions.h"
#include "wxstackedbarchartoptions.h"
#include "wxstackedcolumnchartoptions.h"
#include "wxtimeserieschart.h"
#include "wxchartsdatasetid.h"
#include "wxchartsdatasettheme.h"
#include <wx/sharedptr.h>
#include <map>

/// \defgroup themeclasses

/// Represent a wxCharts theme.

/// \ingroup themeclasses
class WXCHARTS_EXPORT wxChartsTheme
{
public:
    wxChartsTheme();

    wxAreaChartOptions::ptr GetAreaChartOptions();
    wxBarChartOptions::ptr GetBarChartOptions();
    wxBoxPlotOptions::ptr GetBoxPlotOptions();
    wxBubbleChartOptions::ptr GetBubbleChartOptions();
    wxCandlestickChartOptions::ptr GetCandlestickChartOptions();
    wxColumnChartOptions::ptr GetColumnChartOptions();
    wxDoughnutChartOptions::ptr GetDoughnutChartOptions();
    wxHistogramOptions::ptr GetHistogramOptions();
    wxLineChartOptions::ptr GetLineChartOptions();
    wxMath2DPlotOptions::ptr GetMath2DPlotOptions();
    wxOHLCChartOptions::ptr GetOHLCChartOptions();
    wxPieChartOptions::ptr GetPieChartOptions();
    wxPolarAreaChartOptions::ptr GetPolarAreaChartOptions();
    wxRadarChartOptions::ptr GetRadarChartOptions();
    wxScatterPlotOptions::ptr GetScatterPlotOptions();
    wxStackedBarChartOptions::ptr GetStackedBarChartOptions();
    wxStackedColumnChartOptions::ptr GetStackedColumnChartOptions();
    wxTimeSeriesChartOptions::ptr GetTimeSeriesChartOptions();

    wxSharedPtr<wxChartsDatasetTheme> GetDatasetTheme(const wxChartsDatasetId& id);
    void SetDatasetTheme(const wxChartsDatasetId& id, wxSharedPtr<wxChartsDatasetTheme> theme);

private:
    wxAreaChartOptions::ptr m_areaChartOptions;
    wxBarChartOptions::ptr m_barChartOptions;
    wxBoxPlotOptions::ptr m_boxPlotOptions;
    wxBubbleChartOptions::ptr m_bubbleChartOptions;
    wxCandlestickChartOptions::ptr m_candlestickChartOptions;
    wxColumnChartOptions::ptr m_columnChartOptions;
    wxDoughnutChartOptions::ptr m_doughnutChartOptions;
    wxHistogramOptions::ptr m_histogramOptions;
    wxLineChartOptions::ptr m_lineChartOptions;
    wxMath2DPlotOptions::ptr m_math2DPlotOptions;
    wxOHLCChartOptions::ptr m_ohlcChartOptions;
    wxPieChartOptions::ptr m_pieChartOptions;
    wxPolarAreaChartOptions::ptr m_polarAreaChartOptions;
    wxRadarChartOptions::ptr m_radarChartOptions;
    wxScatterPlotOptions::ptr m_scatterPlotOptions;
    wxStackedBarChartOptions::ptr m_stackedBarChartOptions;
    wxStackedColumnChartOptions::ptr m_stackedColumnChartOptions;
    wxTimeSeriesChartOptions::ptr m_timeSeriesChartOptions;
    std::map<wxChartsDatasetId, wxSharedPtr<wxChartsDatasetTheme>> m_datasetThemes;
};

extern wxSharedPtr<wxChartsTheme> wxChartsDefaultTheme;

#endif
