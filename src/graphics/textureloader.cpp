#include "graphics/textureloader.h"

#include <FreeImage.h>

using namespace nautical;
using namespace nautical::graphics;

TextureLoader::TextureLoader()
{
    // not doing the dictionary for now
}

TextureLoader::~TextureLoader()
{
    // not doing the dictionary for now
}

std::string TextureLoader::loadTexture(std::string name, const char* fileLoc)
{
    FIBITMAP* bitmap =
        FreeImage_Load(FreeImage_GetFileType(fileLoc, 0), fileLoc);

    FIBITMAP* image = FreeImage_ConvertTo32Bits(bitmap);

    GLuint texture;

    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, FreeImage_GetWidth(image),
                 FreeImage_GetHeight(image), 0, GL_BGRA, GL_UNSIGNED_BYTE,
                 static_cast<void*>(FreeImage_GetBits(image)));

    FreeImage_Unload(image);
    FreeImage_Unload(bitmap);

    if(_dict.find(name) != _dict.end())
    {
        return nullptr;
    }

    _dict[name] = texture;

    return name;
}
