#pragma once

#include "AbstractDebugImplementation.h"

namespace glo {

class FallbackDebugImplementation : public AbstractDebugImplementation
{
public:
    FallbackDebugImplementation();

    virtual bool isFallback() override;

    virtual void enable() override;
    virtual void disable() override;
    virtual void setSynchronous(bool synchronous) override;
    virtual void insertMessage(const DebugMessage & message) override;
    virtual void controlMessages(gl::GLenum source, gl::GLenum type, gl::GLenum severity, gl::GLsizei count, const gl::GLuint * ids, gl::GLboolean enabled) override;
protected:
    bool m_enabled;
};

} // namespace glo