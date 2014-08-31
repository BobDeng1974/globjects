#pragma once

#include <globjects-base/Singleton.h>

#include "AbstractBufferImplementation.h"


namespace glo
{

class BufferImplementation_Legacy : public AbstractBufferImplementation
    , public Singleton<BufferImplementation_Legacy>
{
public:
    virtual gl::GLuint create() const override;
    virtual void destroy(gl::GLuint id) const override;

    virtual void * map(const Buffer * buffer, gl::GLenum access) const override;
    virtual void * mapRange(const Buffer * buffer, gl::GLintptr offset, gl::GLsizeiptr length, gl::BufferAccessMask access) const override;
    virtual bool unmap(const Buffer * buffer) const override;

    virtual void setData(const Buffer * buffer, gl::GLsizeiptr size, const gl::GLvoid * data, gl::GLenum usage) const override;
    virtual void setSubData(const Buffer * buffer, gl::GLintptr offset, gl::GLsizeiptr size, const gl::GLvoid * data) const override;
    virtual void setStorage(const Buffer * buffer, gl::GLsizeiptr size, const gl::GLvoid * data, gl::MapBufferUsageMask flags) const override;

    virtual void copySubData(const Buffer * buffer, Buffer * other, gl::GLintptr readOffset, gl::GLintptr writeOffset, gl::GLsizeiptr size) const override;

    virtual gl::GLint getParameter(const Buffer * buffer, gl::GLenum pname) const override;
    virtual gl::GLint64 getParameter64(const Buffer * buffer, gl::GLenum pname) const override;
    virtual void * getPointer(const Buffer * buffer, gl::GLenum pname) const override;

    virtual void clearData(const Buffer * buffer, gl::GLenum internalformat, gl::GLenum format, gl::GLenum type, const void * data) const override;
    virtual void clearSubData(const Buffer * buffer, gl::GLenum internalformat, gl::GLintptr offset, gl::GLsizeiptr size, gl::GLenum format, gl::GLenum type, const void * data) const override;

    virtual void flushMappedRange(const Buffer * buffer, gl::GLintptr offset, gl::GLsizeiptr length) const override;

    virtual void getBufferSubData(const Buffer * buffer, gl::GLintptr offset, gl::GLsizeiptr size, gl::GLvoid * data) const override;

public:
    static gl::GLenum s_workingTarget;
};

} // namespace glo