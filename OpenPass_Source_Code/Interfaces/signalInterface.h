/******************************************************************************
* Copyright (c) 2016 ITK Engineering AG.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

#ifndef SIGNALINTERFACE
#define SIGNALINTERFACE

//-----------------------------------------------------------------------------
//! This interface provides access to common signal operations
//-----------------------------------------------------------------------------
class SignalInterface
{
public:
    SignalInterface() = default;
    SignalInterface(const SignalInterface&) = delete;
    SignalInterface(SignalInterface&&) = delete;
    SignalInterface& operator=(const SignalInterface&) = delete;
    SignalInterface& operator=(SignalInterface&&) = delete;
    virtual ~SignalInterface() = default;

    //-----------------------------------------------------------------------------
    //! String conversion of signal
    //-----------------------------------------------------------------------------
    virtual operator std::string() const = 0;
	// VisualStudio 2015 does not allow explicit and virtual

private:
    friend std::ostream& operator<<(std::ostream&,
                                    const SignalInterface&);
};

#endif // SIGNALINTERFACE

