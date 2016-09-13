#include <GL/glut.h>
#include <dlfcn.h>
#include "Graph.h"


extern "C"
{
void * keyDown(int key)
{
        typedef Graph* create_l();
        void * handle = dlopen("./libline.so", RTLD_LAZY);
        create_l * create_line = (create_l *)dlsym(handle, "create");

        typedef Graph* create_r();
        void * handle2 = dlopen("./librect.so", RTLD_LAZY);
        create_r * create_rect = (create_r *)dlsym(handle2, "create");

	typedef Graph* create_p();
        void * handle3 = dlopen("./libpoly.so", RTLD_LAZY);
        create_p * create_poly = (create_p *)dlsym(handle3, "create");

switch(key){
    case GLUT_KEY_F1:
        return create_line();        
             
    case GLUT_KEY_F2:
        return create_rect();

    case GLUT_KEY_F4:
	return create_poly();
}
}
}
