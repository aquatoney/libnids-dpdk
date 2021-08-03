#include "callback.h"
#include <string.h>
#include <arpa/inet.h>

#define int_ntoa(x)	inet_ntoa(*((struct in_addr *)&x))

// struct tuple4 contains addresses and port numbers of the TCP connections
// the following auxiliary function produces a string looking like
// 10.0.0.1,1024,10.0.0.2,23
void
adres (struct tuple4 addr)
{
  struct in_addr addr1, addr2;
  memcpy(&addr1, &(addr.saddr), 4);
  memcpy(&addr2, &(addr.daddr), 4);

  printf("\n");
  printf("nids src ip: %s, ", inet_ntoa(addr1));
  printf("nids src port: %hu, ", ntohs(addr.source));
  printf("nids dst ip: %s, ", inet_ntoa(addr2));
  printf("nids dst port: %hu, ", ntohs(addr.dest));
}

void
tcp_callback (struct tcp_stream *a_tcp, void ** this_time_not_needed)
{
  // printf("Get into TCP Callback\n");
  // char buf[1024];
  // adres(a_tcp->addr);
  // adres(buf, a_tcp->addr);
  // strcpy (buf, adres (a_tcp->addr)); // we put conn params into buf
  if (a_tcp->nids_state == NIDS_JUST_EST) {
      // printf("Ready to print buf (EST)\n");
      a_tcp->client.collect++; // we want data received by a client
      a_tcp->server.collect++; // and by a server, too
      // printf("%s established\n", buf);
      return;
    }
  if (a_tcp->nids_state == NIDS_CLOSE) {
      // printf("Ready to print buf (CLOSE)\n");
      // connection has been closed normally
      // printf("%s closing\n", buf);
      return;
  }
  if (a_tcp->nids_state == NIDS_RESET) {
      // printf("Ready to print buf (RESET)\n");
      // connection has been closed by RST
      // printf("%s reset\n", buf);
      return;
  }

  if (a_tcp->nids_state == NIDS_DATA) {
      // printf("Ready to print buf (DATA)\n");
    // new data has arrived; gotta determine in what direction
    // and if it's urgent or not

   //  struct half_stream *hlf;

   //  if (a_tcp->client.count_new) {
   //          // new data for client
  	//   hlf = &a_tcp->client; // from now on, we will deal with hlf var,
   //                                // which will point to client side of conn
  	//   strcat (buf, "(<-)"); // symbolic direction of data
  	// }
   //  else {
  	//   hlf = &a_tcp->server; // analogical
  	//   strcat (buf, "(->)");
  	// }
   //  printf("%s",buf); // we print the connection parameters
  }
  return ;
}