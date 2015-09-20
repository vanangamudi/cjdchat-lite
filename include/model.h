#ifndef __MODEL_H__
#define __MODEL_H__

typedef char ChannelName[16];
typedef char NetAddr[40];
typedef char Nickname[16];
typedef char MessageContent[128]

struct Peer {
  NetAddr addr;
  Nickname nickname;
};

struct Channel {
  ChannelName name;
  map<string, Peer> members;
};

struct Self {
  Nickname nickname[16];
  map<string, Peer> peers;
  map<string, Channel>  channels;

  stack<string> previous_channels;
  ChannelName current_channel;
};

struct Message{
  enum {UNKNOWN, CONTROL, DATA} Type;
  enum {JOIN, QUIT, PART, PARTALL} ControlCode;

  Type type;
  ControlCode code;
  ChannelName channel;  
};

int Channel_addMember(Channel* , const Peer);
int Channel_removeMember(Channel*, Nickname);


Message::Type Message_create(char* string); //will parse the string and construct the message



//return type may change - not well thought
bool data_message_handler(Message);
bool control_message_handler(Message);

// used by control handler
bool WRU_sender(NetAddr);
bool IAM_handler(Message);
bool JOIN_handler(Message);
bool QUIT_handler(Message);
bool PART_handler(Message);
bool PARTALL_handler(Message);
#endif // __MODEL_H__
