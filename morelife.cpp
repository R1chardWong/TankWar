#include <morelife.h>


moreLife::moreLife()
{
    toolLook.load((rootdir+"pic\\morelife.png").c_str());
    toolLook=resizePic(toolLook,BASESIZE,BASESIZE);
}
