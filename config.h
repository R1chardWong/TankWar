#ifndef CONFIG_H
#define CONFIG_H

#include <string>
extern char map[26][27];//需要定义为外部变量，否则会与bullet.h中产生重复定义
extern const std::string rootdir;//根目录

#define resizePic(p,w,h) p.scaled(w,h,Qt::AspectRatioMode::IgnoreAspectRatio,Qt::TransformationMode::SmoothTransformation)
//一个resizepic函数

#define WIDTH 600
#define HEIGHT 600
#define BASESIZE 20
#define SIZE 40

enum direct{up,right,down,left};//方向枚举变量，上下左右

#endif // CONFIG_H
