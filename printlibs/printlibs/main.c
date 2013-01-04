//
//  main.c
//  printlibs
//
//  Created by Christopher Martin on 12/31/12.
//  Copyright (c) 2012 Shadyproject. All rights reserved.
//

#include <stdio.h>
#include <mach-o/dyld.h>

int main(int argc, const char * argv[])
{
    const char *s;
    uint32_t i, image_max;
    
    image_max = _dyld_image_count();
    for (i = 0; i < image_max; i++) {
        if ((s = _dyld_get_image_name(i)))
            printf("%10p %s\n", _dyld_get_image_header(i), s);
        else
            printf("image at index %u (no name?)\n", i);
    }
    
    return 0;
}

