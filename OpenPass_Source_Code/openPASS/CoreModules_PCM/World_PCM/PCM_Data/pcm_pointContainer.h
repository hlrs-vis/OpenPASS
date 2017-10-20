/******************************************************************************
* Copyright (c) 2017 ITK Engineering GmbH.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

//-----------------------------------------------------------------------------
//! @file  pcm_pointContainer.h
//! @brief class to store a points.
//!
//! This class is responsible to manage data of pcm points.
//-----------------------------------------------------------------------------

#ifndef PCM_POINTCONTAINER_H
#define PCM_POINTCONTAINER_H

#include <QString>
#include <map>
#include "pcm_point.h"
#include "pcm_lineSegment.h"

/*!
 * \brief The PCM_PointContainer class
 * This class is responsible to manage data of a pcm points.
 */
class PCM_PointContainer
{
public:
    //-----------------------------------------------------------------------------
    //! Constructor
    //-----------------------------------------------------------------------------
    PCM_PointContainer() = default;

    // removing operators
    PCM_PointContainer(const PCM_PointContainer &) = default;
    PCM_PointContainer(PCM_PointContainer &&) = default;
    PCM_PointContainer &operator=(const PCM_PointContainer &) = delete;
    PCM_PointContainer &operator=(PCM_PointContainer &&) = delete;

    //-----------------------------------------------------------------------------
    //! Destructor
    //-----------------------------------------------------------------------------
    ~PCM_PointContainer();

    //-----------------------------------------------------------------------------
    //! Function to add a point to the line
    //!
    //! @param[in]     point    PCM_Point to add
    //! @return                 true on success
    //-----------------------------------------------------------------------------
    bool AddPCM_Point(const PCM_Point *point);

    //-----------------------------------------------------------------------------
    //! Get the map of points of the line
    //!
    //! @return                 map of points
    //-----------------------------------------------------------------------------
    const std::map<int, const PCM_Point *> *GetPointMap() const;

    //-----------------------------------------------------------------------------
    //! Check if a point with this id is already present in the line.
    //!
    //! @param[in]     id       id of point
    //! @return                 true if point already exists,
    //!                         false else
    //-----------------------------------------------------------------------------
    bool isPointPresent(int id) const;

    //-----------------------------------------------------------------------------
    //! Get a point by the id
    //!
    //! @param[in]     id       id of point
    //! @return                 pointer the the PCM_Point with this id,
    //!                         nullptr if point does not exist
    //-----------------------------------------------------------------------------
    const PCM_Point *GetPointById(int id) const;

    //-----------------------------------------------------------------------------
    //! Retrieve the nearest line segment(two points of a line) from a pcm point
    //! either in a specific viewDirection, within a range or none.
    //!
    //! @param[in]     point           base point
    //! @param[in]     viewDirection   viewDirection (INFINITY if no viewDirection is set in
    //!                                in function)
    //! @param[in]     range           range (INFINITY if no range is set in
    //!                                in function)
    //! @return                        pair of points which are the nearest,
    //!                                pair of nullptr if there are no points
    //-----------------------------------------------------------------------------
    PCM_LineSegment GetNearestLineSegment(const PCM_Point *point,
                                          double viewDirection = INFINITY,
                                          double range = INFINITY) const;

    //-----------------------------------------------------------------------------
    //! Retrieve the nearest point on a line segment of all lines from a
    //! pcm point either in a specific viewDirection, within a range or none.
    //!
    //! @param[in]     point           base point
    //! @param[in]     viewDirection   viewDirection (INFINITY if no viewDirection is set in
    //!                                in function)
    //! @param[in]     range           range (INFINITY if no range is set in
    //!                                in function)
    //! @return                        nearest point on line
    //-----------------------------------------------------------------------------
    PCM_Point GetNearestPoint(const PCM_Point *point,
                              double viewDirection = INFINITY,
                              double range = INFINITY) const;

private:
    std::map<int, const PCM_Point *> pointMap;  //!< map of points
};

#endif // PCM_POINTCONTAINER_H
