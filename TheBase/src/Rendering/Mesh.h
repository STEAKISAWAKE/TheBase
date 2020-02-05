#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include "../Utils/Vector.h"
#include "../Math/Vec3.h"
#include "../Math/Vec2.h"

typedef struct _Mesh // A mesh that can be rendered
{
    void* p_vertices;
    unsigned int vertex_count;
    unsigned int vertex_stride;
    int position_offset;
    int texcoord_offset;
    int normal_offset;
} Mesh;

typedef struct _MeshParsingData // Used when parsing a file to get the vert data (You probably shouln't use unless you are making a new file importer)
{
    /* Data */
    float* p_positions;
    float* p_texcoords;
    float* p_normals;
    unsigned int* p_faces;

    /* Sizes */
    unsigned int position_count;
    unsigned int normal_count;
    unsigned int texcoord_count;
    unsigned int face_count;
    unsigned int position_width;
    unsigned int normal_width;
    unsigned int texcoord_width;
    unsigned int face_width;

} MeshParsingData;


/* Declaration */

Mesh CreateMeshFromFile(const char* p_file_name);
unsigned int objpar(const char* p_string, unsigned int string_size, void* p_buffer, struct _MeshParsingData* p_data);
unsigned int objpar_build_mesh(const struct _MeshParsingData* p_data, void* p_buffer, struct _Mesh* p_mesh);
unsigned int objpar_internal_v(const char* p_string, unsigned int* p_index, unsigned int string_size, float** pp_vbuff, unsigned int vertex_width);
unsigned int objpar_internal_vn(const char* p_string, unsigned int* p_index, unsigned int string_size, float** pp_nbuff, unsigned int normal_width);
unsigned int objpar_internal_vt(const char* p_string, unsigned int* p_index, unsigned int string_size, float** pp_tbuff, unsigned int texcoord_width);
unsigned int objpar_internal_f(const char* p_string, unsigned int* p_index, unsigned int string_size, unsigned int** pp_fbuff, unsigned int face_width);
unsigned int objpar_internal_comment(const char* p_string, unsigned int* p_index, unsigned int string_size);
unsigned int objpar_internal_newline(const char* p_string, unsigned int* p_index, unsigned int string_size, unsigned int* p_space_count);

#endif // MESH_H_INCLUDED
