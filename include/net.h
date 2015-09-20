
typedef char[128] Data;
typedef char[40] NetAddr;

int net_unicast(Data, NetAddr);
int net_broadcast(Data, vector<NetAddr>);

//not well thought
int net_receive();
