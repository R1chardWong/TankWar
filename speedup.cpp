#include <speedup.h>


speedUP::speedUP()
{
    toolLook.load((rootdir+"pic\\speedup.png").c_str());
    toolLook=resizePic(toolLook,BASESIZE,BASESIZE);
}
