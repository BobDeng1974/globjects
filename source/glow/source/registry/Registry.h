#pragma once

#include <GL/glew.h>

#include <unordered_map>

#include <glow/glow_api.h>

namespace glow
{

class ObjectRegistry;
class ExtensionRegistry;
class ImplementationRegistry;
class NamedStringRegistry;

class GLOW_API Registry
{
public:
    static long long registerCurrentContext();
    static void setContext(long long contextId);
    static void deregisterCurrentContext();

    static Registry & current();

    ObjectRegistry & objects();
    ExtensionRegistry & extensions();
    ImplementationRegistry & implementations();
    NamedStringRegistry & namedStrings();
private:
    Registry();
    ~Registry();

    static Registry * s_currentRegistry;
    static std::unordered_map<long long, Registry *> s_registries;
private:
    ObjectRegistry * m_objects;
    ExtensionRegistry * m_extensions;
    ImplementationRegistry * m_implementations;
    NamedStringRegistry * m_namedStrings;
};

} // namespace glow