/*********************************************
 *      @file   memory/fault.c
 *
 *      @brief  例外の割り込みの機能
 *
 *      @update vxdora
 *
 *      @update mindows03c
 ********************************************/

#include <memory.h>
#include <graphics.h>

extern GraphicsInfo graphicsInfo;

//
//      EmptyHandler
//      @arg    :   なし
//      @return :   なし
//      @brief  :   意図しない例外の捕捉
//      @author :   vxdora
//      @update :   mindows03c
//
void EmptyHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"Empty Handler", 0xFFFFFF);
    while (1);
}

void DeHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"DE Error", 0xFFFFFF);
    while (1);
}

void DbHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"DB Error", 0xFFFFFF);
    while (1);
}

void NmiHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"NMI Error", 0xFFFFFF);
    while (1);
}

void BpHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"BP Error", 0xFFFFFF);
    while (1);
}

void OfHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"OF Error", 0xFFFFFF);
    while (1);
}

void BrHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"BR Error", 0xFFFFFF);
    while (1);
}

void UdHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"UD Error", 0xFFFFFF);
    while (1);
}

void NmHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"NM Error", 0xFFFFFF);
    while (1);
}

void DfHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"DF Error", 0xFFFFFF);
    while (1);
}

void TsHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"TS Error", 0xFFFFFF);
    while (1);
}

void NpHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"NP Error", 0xFFFFFF);
    while (1);
}

void SsHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"SS Error", 0xFFFFFF);
    while (1);
}

void GpHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"GP Error", 0xFFFFFF);
    while (1);
}

void PfHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"PF Error", 0xFFFFFF);
    while (1);
}

void MfHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"MF Error", 0xFFFFFF);
    while (1);
}

void AcHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"AC Error", 0xFFFFFF);
    while (1);
}

void McHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"MC Error", 0xFFFFFF);
    while (1);
}

void XmHandler(void) {
	DrawRectangle(3, 3, 150, 40, 0x000000);
    DrawString(5, 5, (unsigned char *)"XM Error", 0xFFFFFF);
    while (1);
}
