#ifndef _INC_NAPENFORCEMENTCLIENT
#define _INC_NAPENFORCEMENTCLIENT

#if (_WIN32_WINNT >= 0x0600)

#define defaultProtocolMaxSize    0x0FA0
#define maxProtocolMaxSize        0xFFFF
#define minProtocolMaxSize        0x012C
#define ProtocolMaxSize           range(minProtocolMaxSize, maxProtocolMaxSize)

  typedef struct tagConnections {
    UINT16                          count;
    INapEnforcementClientConnection **connections;
  }Connections;

#ifndef NAPTypes
#define NAPTypes
  typedef FILETIME ProbationTime;
  typedef UINT32 ProtocolMaxSize;
  typedef UINT32 NapComponentId;
  typedef NapComponentId SystemHealthEntityId;
  typedef NapComponentId EnforcementEntityId;
  typedef UINT16 SystemHealthEntityCount;
  typedef UINT16 EnforcementEntityCount;
  typedef CountedString StringCorrelationId;
  typedef GUID ConnectionId;
  typedef UINT8 Percentage;
  typedef UINT32 MessageId;
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif _INC_NAPENFORCEMENTCLIENT