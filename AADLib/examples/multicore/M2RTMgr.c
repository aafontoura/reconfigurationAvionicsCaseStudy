#include <stdint.h>
#include <stdio.h>
#include "MsgType.h"

static uint8_t FirstTimeThrough	= TRUE;
static uint32_t	MessageCounter	= 0;


void m2rtinit(initmsg *msg){
	printf("RT Bus Manager 2 Remote Terminal Initialization - Start\n");
	msg->InitializationComplete = TRUE;
	printf("RT Bus Manager 2 Remote Terminal  - Complete\n");
}

void m2rtmgr(initmsg msg, busmsg *RTtoBCMsg){
	if(msg.InitializationComplete){
		if(FirstTimeThrough){
			printf("RT Bus Manager 2 Remote Terminal  - Start\n");
			FirstTimeThrough = FALSE;
		}
		if(MessageCounter == 0){
			RTtoBCMsg->MsgQueue[0].Msg[0]=1;
			RTtoBCMsg->MsgQueue[0].Msg[1]++;
			MessageCounter = 500;				// 5 seconds
			printf("RT Bus Mgr 2 Sending Message (%d) to BC\n",RTtoBCMsg->MsgQueue[0].Msg[1]);
		}
		else {
			RTtoBCMsg->MsgQueue[0].Msg[0]=0;
			MessageCounter--;
		}
	}
}
