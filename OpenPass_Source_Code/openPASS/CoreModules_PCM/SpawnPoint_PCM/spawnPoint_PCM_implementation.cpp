/******************************************************************************
* Copyright (c) 2017 ITK Engineering GmbH.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

#include "spawnPoint_PCM_implementation.h"

SpawnPoint_PCM_Implementation::SpawnPoint_PCM_Implementation(StochasticsInterface
                                                                     *stochastics, WorldInterface *world, const ParameterInterface *parameters,
                                                                     const CallbackInterface *callbacks):
    SpawnPointInterface(stochastics, world, parameters, callbacks)
{
    std::map<int, double> parameterMapDoubleExternal = GetParameters()->GetParametersDouble();
    foreach (auto &iterator, parameterMapDouble) {
        int id = iterator.first;
        try {
            parameterMapDouble.at(id)->SetValue(parameterMapDoubleExternal.at(id));
        } catch (const std::out_of_range &) {
            parameterMapDouble.at(id)->SetValue(-1);
        }
    }
}

void SpawnPoint_PCM_Implementation::SetSpawnItem(SpawnItemParameterInterface &spawnItem,
                                                     int maxIndex)
{
    // set index
    spawnItem.SetIndex(maxIndex);

    // set next spawn time
    spawnItem.SetNextTimeOffset(-1);

    spawnItem.SetPositionX(positionX.GetValue());
    spawnItem.SetPositionY(positionY.GetValue());
    spawnItem.SetVelocityX(velocityX.GetValue());
    spawnItem.SetVelocityY(velocityY.GetValue());
    spawnItem.SetAccelerationX(accelerationX.GetValue());
    spawnItem.SetAccelerationY(accelerationY.GetValue());
    spawnItem.SetYawAngle(yawAngle.GetValue());

    return;
}