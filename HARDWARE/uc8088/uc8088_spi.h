#ifndef __UC8088_SPI_H__
#define __UC8088_SPI_H__

#include "stdlib.h"
#include "sys.h"
#define SPI2_CS 				 PBout(12)

#define READ_CMD			0x0B	//读命令
#define WRITE_CMD			0x02	//写命令

#define Buf_addr			(0x33ac00)
#define SPI_BUF_LEN		(4096)
//typedef struct
//{
//	u32 sWrite;
//	u32 sRead;
//	u8 ucBuf[SPI_BUF_LEN];
//}STU_SPI_QUEUE;


//typedef struct
//{
//  u8  cmd_type;
//  u8  cmd_data[32];
//}TracealyzerCommandType;

//#define iRescvBufBaseAddr  (0x0033b490)	//this is the base address in spi device, it must be changed accordingly
//#define config_enable_Addr  (iRescvBufBaseAddr + 16)
//#define config_struct_Addr  (iRescvBufBaseAddr + 40)

//#define buffer_head1_Addr  (iRescvBufBaseAddr + 104)
//#define buffer_head2_Addr  (iRescvBufBaseAddr + 116)

//#define buffer1_Addr  (iRescvBufBaseAddr + 132)
//#define buffer2_Addr  (iRescvBufBaseAddr + 132 + 2560)


extern void* memset ( void * ptr, int value, size_t num );
void uc8088_init(void);

u16 uc8088_read_memory(const u32 Addr, register u8* pBuffer, u16 NumByteToRead);	//读Num个Byte
void uc8088_write_memory(const u32 Addr, u8* pBuffer, u16 NumByteToRead);	//写num个字节

void uc8088_write_u8(const u32 addr, u8 wdata);			//写一个字节
void uc8088_write_u16(const u32 addr, u16 wdata);		//写一个u16数据（2个字节）
void uc8088_write_u32(const u32 addr, u32 wdata);		//写一个u32数据（4个字节）
u8 uc8088_read_u8(const u32 addr);									//读一个u8数据
u16 uc8088_read_u16(const u32 addr);								//读一个u16数据
u32 uc8088_read_u32(const u32 addr);								//读一个u32数据
void uc8088_read_2_u32(const u32 addr, u32* r1, u32* r2);							//读两个u32数据
#endif
