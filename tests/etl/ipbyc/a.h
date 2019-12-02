#ifndef __A_H__
#define __A_H__

#ifdef __cplusplus
extern "C" {
#endif
typedef struct
{
    union
    {
        unsigned int ip_dw;
        unsigned char ip_b[4];
    };
}IPV4;

typedef struct
{
    IPV4 ip_beg;
    IPV4 ip_end;
    char country[256];
    char province[32];
}IP_INFO;

bool ipv4_read(char *fname);

IP_INFO *find_ip(int ip);

#ifdef __cplusplus
}
#endif

#endif // __A_H__
