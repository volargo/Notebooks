/*
 * =====================================================================================
 *
 *       Filename:  private_class.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/2017 12:38:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

class Box {
    public:
        double  length;
        double  setWidth(double);
        double  getWidth(void);
        
    private:
        double  width;
};

double Box::getWidth(void) {
    return width;
}

double Box::setWidth(double wid) {
    width = wid;
}

int main(void)
{
    Box     box;

    box.length = 10.0;
    cout << "Length of box: " << box.length << endl;

    // box.width = 10.0F; // Error: 成员width是私有的, 编译会出错
    box.setWidth(10.0F);
    cout << "Width of box: " << box.getWidth() << endl;

    return 0;
}
