// Github username: yonisaka
// Aim: Print Ip Address and Hostname from client
// Date: 4/10/2022
package main

import (
	"fmt"
	"net"
	"net/http"
	"strings"
)

type Client struct {
	IP   string
	Hostname string
}

func main() {
	handlerFunc := http.HandlerFunc(handleRequest)
    http.Handle("/", handlerFunc)
    http.ListenAndServe(":8080", nil)
}

func handleRequest(w http.ResponseWriter, r *http.Request) {
    ip, err := getIP(r)
    if err != nil {
        w.WriteHeader(400)
        w.Write([]byte("No valid ip"))
    }
	hostname, err := getHostname(r)
	if err != nil {
		w.WriteHeader(400)
		w.Write([]byte("No valid hostname"))
	}
    w.WriteHeader(200)
	w.Write([]byte("IP: " + ip + " Hostname: " + hostname))
}

func getHostname(r *http.Request) (string, error) {
	hostname := r.Header.Get("Host")

	return hostname, nil
}

func getIP(r *http.Request) (string, error) {
    //Get IP from the X-REAL-IP header
    ip := r.Header.Get("X-REAL-IP")
    netIP := net.ParseIP(ip)
    if netIP != nil {
        return ip, nil
    }

    //Get IP from X-FORWARDED-FOR header
    ips := r.Header.Get("X-FORWARDED-FOR")
    splitIps := strings.Split(ips, ",")
    for _, ip := range splitIps {
        netIP := net.ParseIP(ip)
        if netIP != nil {
            return ip, nil
        }
    }

    //Get IP from RemoteAddr
    ip, _, err := net.SplitHostPort(r.RemoteAddr)
    if err != nil {
        return "", err
    }
    netIP = net.ParseIP(ip)
    if netIP != nil {
        return ip, nil
    }
    return "", fmt.Errorf("No valid ip found")
}