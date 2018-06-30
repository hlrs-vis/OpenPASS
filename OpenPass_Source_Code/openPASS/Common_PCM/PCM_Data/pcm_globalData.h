/******************************************************************************
* Copyright (c) 2017 ITK Engineering GmbH.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

//-----------------------------------------------------------------------------
//! @file  pcm_globalData.h
//! @brief class to store global data of pcm.
//!
//! This class is responsible to manage global data.
//-----------------------------------------------------------------------------

#ifndef PCM_GLOBALDATA_H
#define PCM_GLOBALDATA_H

#include "QString"

/*!
 * \brief The PCM_GlobalData class
 * This class is responsible to manage global data.
 */
class PCM_GlobalData
{
public:
    //-----------------------------------------------------------------------------
    //! Default Constructor
    //-----------------------------------------------------------------------------
    PCM_GlobalData() = default;

    // removing operators
    PCM_GlobalData(const PCM_GlobalData &) = default;
    PCM_GlobalData(PCM_GlobalData &&) = default;
    PCM_GlobalData &operator=(const PCM_GlobalData &) = delete;
    PCM_GlobalData &operator=(PCM_GlobalData &&) = delete;

    //-----------------------------------------------------------------------------
    //! Destructor
    //-----------------------------------------------------------------------------
    virtual ~PCM_GlobalData() = default;

    /*!
     * \name
     * Standard Getter and Setter
     * @{
     */
    double GetOffsetX() const;
    void SetOffsetX(double value);

    double GetOffsetY() const;
    void SetOffsetY(double value);

    int GetParticipants() const;
    void SetParticipants(int value);

    int GetSimulationVersion() const;
    void SetSimulationVersion(int value);
    /*!
     * @}
     */

private:
    double offsetX;         //!< offset X
    double offsetY;         //!< offset Y
    int participants;       //!< number of participants
    int simulationVersion;  //!< simulation version
};

#endif // PCM_GLOBALDATA_H
