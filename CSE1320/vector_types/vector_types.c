#include "vector_types.h"

// This will add any vector array with another and print it
void vect_add2f(float *vect1, float *vect2, int max)
{
	float result[max];

	for(int i = 0; i < max; i++)
	{
		result[i] = vect1[i] + vect2[i];
	}
	
	printf("For vec2f...\n");
	printf("[%g, %g] + [%g, %g] = [%g, %g]\n",vect1[0],
						vect1[1],
						vect2[0],
						vect2[1],
						result[0],
						result[1]); 
}

void vect_add3f(float *vect1, float *vect2, int max)
{
        float result[max];

        for(int i = 0; i < max; i++)
        {
                result[i] = vect1[i] + vect2[i];
        }

        printf("For vec3f...\n");
        printf("[%g, %g + %g] + [%g, %g, %g] = [%g, %g, %g]\n",vect1[0],
                                                		vect1[1],
								vect1[2],
                                                		vect2[0],
                                                		vect2[1],
								vect2[2],
                                                		result[0],
                                                		result[1],
								result[2]); 
}
void vect_add4f(float *vect1, float *vect2, int max)
{
        float result[max];

        for(int i = 0; i < max; i++)
        {
                result[i] = vect1[i] + vect2[i];
        }

        printf("For vec4f...\n");
        printf("[%g, %g, %g, %g] + [%g, %g, %g, %g] = [%g, %g, %g, %g]\n",vect1[0],
                                                			vect1[1],
									vect1[2],
									vect1[3],
                                                			vect2[0],
                                                			vect2[1],
									vect2[2],
									vect2[3],
                                                			result[0],
                                                			result[1],
									result[2],
									result[3]); 
}

// This will multiple any vector array with another and print it
void vect_mult2f(float *vect1, float mult, int max)
{
	float result[max];
	
	 for(int i = 0; i < max; i++)
        {
                result[i] = vect1[i] * mult;
        }

	printf("%g * [%g, %g] = [%g, %g]\n",mult,
					vect1[0],
					vect1[1],
					result[0],
					result[1]); 

}
void vect_mult3f(float *vect1, float mult, int max)
{
	float result[max];
	
	 for(int i = 0; i < max; i++)
        {
                result[i] = vect1[i] * mult;
        }

	printf("%g * [%g, %g, %g] = [%g, %g, %g]\n",mult,
					vect1[0],
					vect1[1],
					vect1[2],
					result[0],
					result[1],
					result[2]);

}
void vect_mult4f(float *vect1, float mult, int max)
{
	float result[max];
	
	 for(int i = 0; i < max; i++)
        {
                result[i] = vect1[i] * mult;
        }

	printf("%g * [%g, %g, %g, %g] = [%g, %g, %g, %g]\n",mult,
					vect1[0],
					vect1[1],
					vect1[2],
					vect1[3],
					result[0],
					result[1],
					result[2],
 					result[3]);

}

// This will intialize all vectors
vec2f intial_vect2f(vec2f set2)
{
	set2.vector[0] = 22;
	set2.vector[1] = 11;

	return set2;
}

vec3f intial_vect3f(vec3f set3)
{
	set3.vector[0] = 2;
        set3.vector[1] = 3;
	set3.vector[2] = 4;

	return set3;
}

vec4f intial_vect4f(vec4f set4)
{
	set4.vector[0] = 19;
        set4.vector[1] = 10;
	set4.vector[2] = 13;
	set4.vector[3] = 4;

	return set4;
}
/******************** -- MAIN FUNCTION -- *****************/

int main()
{
	// Intializing variables for user input
	vec2f   set2f_1,
		set2f_2;
	vec3f	set3f_1,
		set3f_2;
	vec4f	set4f_1,
		set4f_2;
	float	 multi = 2;

	set2f_1 = intial_vect2f(set2f_1);
	set2f_2 = intial_vect2f(set2f_2);
	set3f_1 = intial_vect3f(set3f_1);
	set3f_2 = intial_vect3f(set3f_2);
	set4f_1 = intial_vect4f(set4f_1);
	set4f_2 = intial_vect4f(set4f_2);


	// Calculations
	vect_add2f(set2f_1.vector,set2f_2.vector,VEC2F_MAX);
	vect_mult2f(set2f_1.vector,multi,VEC2F_MAX);
	vect_add3f(set3f_1.vector,set3f_2.vector,VEC3F_MAX);
	vect_mult3f(set3f_1.vector,multi,VEC3F_MAX);
	vect_add4f(set4f_1.vector,set4f_2.vector,VEC4F_MAX);
	vect_mult4f(set4f_1.vector,multi,VEC4F_MAX);

	return 0;
}
