#include "model.h"

struct ThreadArg {
  
};

queue<Message> sender_queue;

Self self;

//return number of peers to send this message to
// look in sender()
int Message_serializer(Message msg, Data data, NetAddr peers[]);

void* sender(void*){
  
  //create socket?? or we can create thread in main function 
  //recieve it to this via ThreadArg
  char data[128];
  forall (msg in sender_queue){
    peer_count = Message_serializer(msg, data);
    if  (peer_count == 1)
      net_unicast(data, peers[0]);
    else 
      net_broadcast(data, peers, peer_count);
	     
  }
}

//prints data message
//responds to whoareyou with iam message
//adds peer to channels as they join
void* receiver(void*){

  //create socket?? or we can create thread in main function 
  //recieve it to this via ThreadArg

}
int main()
