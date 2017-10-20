/******************************************************************************
* Copyright (c) 2017 ITK Engineering GmbH.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

//-----------------------------------------------------------------------------
//! @file  component.h
//! @brief This file contains the internal representation of a model component
//!        during a simulation run.
//-----------------------------------------------------------------------------

#ifndef COMPONENT_H
#define COMPONENT_H

#include <map>
#include "modelInterface.h"
#include "observationInterface.h"
#include "scheduleItem.h"

namespace SimulationSlave
{

class Channel;
class ModelLibrary;
class Agent;
class ChannelBuffer;

class Component
{
public:
    Component(int id,
              Agent *agent,
              WorldInterface *world) :
        agent(agent),
        id(id),
        modelLibrary(nullptr),
        implementation(nullptr),
        triggerTask(this, agent, world),
        updateTask(this, agent, world)
    {}
    Component(const Component&) = delete;
    Component(Component&&) = delete;
    Component& operator=(const Component&) = delete;
    Component& operator=(Component&&) = delete;

    //-----------------------------------------------------------------------------
    //! Destructor, deletes all saved output channel buffers.
    //-----------------------------------------------------------------------------
    virtual ~Component();


    //-----------------------------------------------------------------------------
    //! Sets the model interface implementation.
    //!
    //! @param[in]     implementation       Model interface implementation to set
    //-----------------------------------------------------------------------------
    void SetImplementation(ModelInterface *implementation);

    //-----------------------------------------------------------------------------
    //! Returns the stored agent.
    //!
    //! @return                             Stored agent
    //-----------------------------------------------------------------------------
    Agent *GetAgent() const;

    //-----------------------------------------------------------------------------
    //! Adds the provided channel with the provided ID to the stored list of input
    //! channels.
    //!
    //! @param[in]     input                Input channel to add
    //! @param[in]     linkId               ID of the channel to add
    //! @return                             Flag if adding the channel was successful
    //-----------------------------------------------------------------------------
    bool AddInputLink(Channel *input, int linkId);

    //-----------------------------------------------------------------------------
    //! Adds the provided channel with the provided ID to the stored list of output
    //! channels.
    //!
    //! @param[in]     output               Output channel to add
    //! @param[in]     linkId               ID of the channel to add
    //! @return                             Flag if adding the channel was successful
    //-----------------------------------------------------------------------------
    bool AddOutputLink(Channel *output, int linkId);

    //-----------------------------------------------------------------------------
    //! Adds the provided observation module with the provided ID to the stored list
    //! of output observation modules.
    //!
    //! @param[in]     observation          Observation module (as interface)to add
    //! @param[in]     linkId               ID of the observation module to add
    //! @return                             Flag if adding the observation module was
    //!                                     successful
    //-----------------------------------------------------------------------------
    bool AddObservationLink(ObservationInterface *observation, int linkId);

    //-----------------------------------------------------------------------------
    //! Returns the map of IDs to stored input channels.
    //!
    //! @return                             Map of IDs to stored input channels
    //-----------------------------------------------------------------------------
    std::map<int, Channel*> &GetInputLinks();

    //-----------------------------------------------------------------------------
    //! Returns the map of IDs to stored output channels.
    //!
    //! @return                             Map of IDs to stored output channels
    //-----------------------------------------------------------------------------
    std::map<int, Channel*> &GetOutputLinks();

    //-----------------------------------------------------------------------------
    //! Returns the map of IDs to stored observation modules.
    //!
    //! @return                             Map of IDs to stored observation modules
    //-----------------------------------------------------------------------------
    const std::map<int, ObservationInterface*> &GetObservationLinks() const;

    //-----------------------------------------------------------------------------
    //! Calls the Trigger method on the stored model library with the stored model
    //! interface implementation and the time parameter provided.
    //!
    //! @param[in]     time                 Observation module (as interface)to add
    //! @return                             False if an error occurred, true otherwise
    //-----------------------------------------------------------------------------
    bool TriggerCycle(int time);

    //-----------------------------------------------------------------------------
    //! Gets the data on the channel with the provided ID by updating the output
    //! via the model library using the stored model instance implementation and
    //! the provided time stamp, then setting this data on the channel with the
    //! provided ID.
    //!
    //! @param[in]     linkId               ID of the output channel
    //! @param[in]     time                 Time stamp for the output
    //! @return                             False if an error occurred, true otherwise
    //-----------------------------------------------------------------------------
    bool AcquireOutputData(int linkId, int time);

    //-----------------------------------------------------------------------------
    //! Releases the data on the channel with the provided ID.
    //!
    //! @param[in]     linkId               ID of the output channel
    //! @return                             False if an error occurred, true otherwise
    //-----------------------------------------------------------------------------
    bool ReleaseOutputData(int linkId);

    //-----------------------------------------------------------------------------
    //! Updates the input data on the input channelwith the provided ID by updating
    //! the input via the model library using the stored model instance implementation
    //! and the provided time stamp.
    //!
    //! @param[in]     linkId               ID of the input channel
    //! @param[in]     time                 Time stamp for the output
    //! @return                             False if an error occurred, true otherwise
    //-----------------------------------------------------------------------------
    bool UpdateInputData(int linkId, int time);

    //-----------------------------------------------------------------------------
    //! Creates a new channel buffer with the provided ID, store it in the stored
    //! list of output channel buffers and return it.
    //!
    //! @param[in]     linkId               ID of the channel output buffer to create
    //! @return                             Created output channel buffer
    //-----------------------------------------------------------------------------
    ChannelBuffer *CreateOutputBuffer(int linkId);

    //-----------------------------------------------------------------------------
    //! Insert the provided channel buffer with the provided ID in the list of stored
    //! input channel buffers.
    //!
    //! @param[in]     linkId               ID of the channel input buffer
    //! @param[in]     buffer               Channel input bufer to set
    //! @return                             False if an error occurred, true otherwise
    //-----------------------------------------------------------------------------
    bool SetInputBuffer(int linkId, ChannelBuffer *buffer);

    //-----------------------------------------------------------------------------
    //! Returns if the stored model interface implementation is defined as init module.
    //!
    //! @return                             Returns false if error occured, otherwise
    //!                                     the flag if stored model interface
    //!                                     implementation is defined as init module
    //-----------------------------------------------------------------------------
    bool GetInit() const;

    //-----------------------------------------------------------------------------
    //! Returns the priority of the stored model interface implementation.
    //!
    //! @return                             Returns std::numeric_limits<int>::min()
    //!                                     if error occured, otherwise the priority
    //!                                     of the stored model interface implementation
    //-----------------------------------------------------------------------------
    int GetPriority() const;

    //-----------------------------------------------------------------------------
    //! Returns the offset time of the stored model interface implementation, i.e.
    //! the time at which this item is inserted for scheduling.
    //!
    //! @return                             Returns 0 if error occured, otherwise
    //!                                     the offset time of the stored model
    //!                                     interface implementation
    //-----------------------------------------------------------------------------
    int GetOffsetTime() const;

    //-----------------------------------------------------------------------------
    //! Returns the response time of the stored model interface implementation.
    //!
    //! @return                             Returns 0 if error occured, otherwise
    //!                                     the respone time of the stored model
    //!                                     interface implementation
    //-----------------------------------------------------------------------------
    int GetResponseTime() const;

    //-----------------------------------------------------------------------------
    //! Returns the cycle time of the stored model interface implementation, i.e.
    //! the time after which it is rescheduled.
    //!
    //! @return                             Returns 0 if error occured, otherwise
    //!                                     the cycle time of the stored model
    //!                                     interface implementation
    //-----------------------------------------------------------------------------
    int GetCycleTime() const;

    //-----------------------------------------------------------------------------
    //! Set the provided model library as library to store.
    //!
    //! @param[in]     modelLibrary         Model library to set
    //! @return                             False if library is already set, true
    //!                                     otherwise
    //-----------------------------------------------------------------------------
    bool SetModelLibrary(ModelLibrary *modelLibrary);

    //-----------------------------------------------------------------------------
    //! Releases this component from the stored library.
    //!
    //! @return                             Result of releasing this component
    //-----------------------------------------------------------------------------
    bool ReleaseFromLibrary();

    //-----------------------------------------------------------------------------
    //! Returns the stored model interface instance.
    //!
    //! @return                             Stored model interface instance
    //-----------------------------------------------------------------------------
    ModelInterface *GetImplementation() const;

    //-----------------------------------------------------------------------------
    //! Returns the stored ID.
    //!
    //! @return                             Stored ID
    //-----------------------------------------------------------------------------
    int GetId() const;

    //-----------------------------------------------------------------------------
    //! Returns a pointer to the schedule item trigger task.
    //!
    //! @return                             Schedule item trigger task
    //-----------------------------------------------------------------------------
    ScheduleItem *GetTriggerTask()
    {
        return &triggerTask;
    }

    //-----------------------------------------------------------------------------
    //! Returns a pointer to the schedule item update task.
    //!
    //! @return                             Schedule item update task
    //-----------------------------------------------------------------------------
    ScheduleItem *GetUpdateTask()
    {
        return &updateTask;
    }

private:
    Agent *agent;
    int id;
    std::map<int, Channel*> inputs;
    std::map<int, Channel*> outputs;
    std::map<int, ObservationInterface*> observations;
    ModelLibrary *modelLibrary;
    ModelInterface *implementation;
    std::map<int, ChannelBuffer*> inputChannelBuffers;
    std::map<int, ChannelBuffer*> outputChannelBuffers;

    ScheduleTriggerItem triggerTask;
    ScheduleUpdateItem updateTask;
};

} // namespace SimulationSlave

#endif // COMPONENT_H
