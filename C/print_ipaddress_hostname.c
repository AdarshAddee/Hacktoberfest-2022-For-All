// GitHub username: vasvolodimir
// Aim: Enumeration network interfaces and print its IP addresses.
// Date: 04 October 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>

#define IPADDRSIZ 16

typedef struct interface_t interface_t;

struct interface_t {
    interface_t *next;
    char ifname[IFNAMSIZ];
    char ipaddr[IPADDRSIZ];
};

static void add_interface(interface_t **list, char *ifname, char *ipaddr)
{
    interface_t *item;

    if (!(item = calloc(1, sizeof(interface_t))))
        return;

    strcpy(item->ifname, ifname);
    strcpy(item->ipaddr, ipaddr);

    item->next = *list;
    *list = item;
}

static int get_if_ipaddr(char *ifname, char *ipaddr)
{
    int fd;
    char *str_addr;
    struct ifreq ifr;
    struct in_addr addr;

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        return -1;

    strcpy(ifr.ifr_name, ifname);

    if (ioctl(fd, SIOCGIFADDR, &ifr) < 0)
    {
        close(fd);
        return -1;
    }

    addr = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;

    if ((str_addr = inet_ntoa(addr)))
        strcpy(ipaddr, str_addr);

    close(fd);
    return 0;
}


int main()
{
    DIR *dir;
    struct dirent *ent;
    interface_t *list = NULL;
    char hostname[NI_MAXHOST] = {};

    if (!(dir = opendir("/sys/class/net")))
        return -1;

    while ((ent = readdir(dir)))
    {
        char ipaddr[IPADDRSIZ] = {};

        if (!get_if_ipaddr(ent->d_name, ipaddr))
            add_interface(&list, ent->d_name, ipaddr);
    }

    closedir(dir);
    gethostname(hostname, NI_MAXHOST);

    printf("Hostname: %s\n", hostname);
    printf("Name\t\tAddress\n");

    for (interface_t *it = list; it; it = it->next)
        printf("%s\t\t%s\n", it->ifname, it->ipaddr ?: "none");

    for (interface_t *it = list; it; it = it->next)
        free(it);

    return 0;
}
