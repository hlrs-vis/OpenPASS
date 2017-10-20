/******************************************************************************
* Copyright (c) 2017 ITK Engineering GmbH.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

#include "pcm_point.h"

PCM_Point::PCM_Point(int id, double inXpos, double inYpos, double inZpos):
    id(id),
    x(inXpos),
    y(inYpos),
    z(inZpos)
{}

int PCM_Point::GetId() const
{
    return id;
}

double PCM_Point::GetX() const
{
    return x;
}

double PCM_Point::GetY() const
{
    return y;
}

double PCM_Point::GetZ() const
{
    return z;
}
