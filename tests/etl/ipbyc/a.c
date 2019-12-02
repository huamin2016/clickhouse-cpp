
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sys/times.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "a.h"

#define  IPV4_MAX 1000000 // ipv4 文件最大行数

static IP_INFO m_ip_info[IPV4_MAX];
static int m_ip_cnt = 0;


int cmpfunc (const void * a, const void * b)
{
    IP_INFO *aa = (IP_INFO *)a;
    IP_INFO *bb = (IP_INFO *)b;

    if (aa->ip_beg.ip_dw > bb->ip_beg.ip_dw)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    return 1; 
}

bool ipv4_read(char *fname)
{
    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("打开%s失败\n", fname);
        return false;
    } 

    char buf[1024];
    while(fgets(buf, sizeof(buf), fp) != NULL)
    {
        char ip_b[16];
        bzero(ip_b, sizeof(ip_b));
        char ip_e[16];
        bzero(ip_e, sizeof(ip_e));

        int ret = sscanf(buf, "%s\t%s\t%s\t%s\n", 
                ip_b, ip_e, 
                m_ip_info[m_ip_cnt].country, 
                m_ip_info[m_ip_cnt].province); 

        if (ret != 4)
        {
            return false;
        }

        unsigned int b = htonl(inet_addr(ip_b));
        if (b == 0xffffffff)
        {
            continue;
        }

        unsigned int e = htonl(inet_addr(ip_e));
        if (e == 0xffffffff)
        {
            continue;
        }

        m_ip_info[m_ip_cnt].ip_beg.ip_dw = b; 
        m_ip_info[m_ip_cnt].ip_end.ip_dw = e; 

        m_ip_cnt ++;
        if (m_ip_cnt >= IPV4_MAX)
        {
            fclose(fp);
            return false;
        }

    }

    qsort(m_ip_info, m_ip_cnt, sizeof(IP_INFO), cmpfunc);
    fclose(fp);
    return true;
}


IP_INFO *find_ip(int ip)
{
    int low = 0;
    int high = m_ip_cnt;
    while(low < high)
    {
        int mid = (low + high)/2;
        if (m_ip_info[mid].ip_end.ip_dw < ip)
        {
            low = mid + 1;
        }
        else if (m_ip_info[mid].ip_beg.ip_dw > ip)
        {
            high = mid -1 ;
        }
        else if (m_ip_info[mid].ip_end.ip_dw >= ip &&
                m_ip_info[mid].ip_beg.ip_dw <= ip)
        {
            // 查找成功
            return &m_ip_info[mid];
        }
        else
        {
            abort();
        }
    }

    //查找失败
    return NULL;
}

int main(int argc, char **argv)
{
    // 加载ip范围文件
    ipv4_read("./ipv4.txt"); 

    char *ip = "1.2.5.4";
    unsigned int num = htonl(inet_addr(ip));

    // 测试查找
    IP_INFO * info = find_ip(num);
    if (info == NULL)
    {
        printf("没找到\n");
        return -1;
    }

    printf("ip_b:%u.%u.%u.%u\nip_e:%u.%u.%u.%u\n country=%s\n",
            info->ip_beg.ip_b[3],
            info->ip_beg.ip_b[2],
            info->ip_beg.ip_b[1],
            info->ip_beg.ip_b[0],
            info->ip_end.ip_b[3],
            info->ip_end.ip_b[2],
            info->ip_end.ip_b[1],
            info->ip_end.ip_b[0],
            info->country
            );
    return 0;
}
