#pragma once
#include "stdint.h"

constexpr auto packet_magic = 0x8fa07d16; // Public IP where CERTIFICATE is installed 143.160.125.22
constexpr auto server_ip = 0x7f000001; // 127.0.0.1 // Local IP 196.252.165.9
constexpr auto server_port =1900; // Public PORT for Certification connection

enum class PacketType
{
	packet_copy_memory,
	packet_get_base_address,
	packet_completed
};

struct PacketCopyMemory
{
	uint32_t dest_process_id;
	uint64_t dest_address;

	uint32_t src_process_id;
	uint64_t src_address;

	uint32_t size;
};

struct PacketGetBaseAddress
{
	uint32_t process_id;
	int name;
};

struct PackedCompleted
{
	uint64_t result;
};

struct PacketHeader
{
	uint32_t   magic;
	PacketType type;
};

struct Packet
{
	PacketHeader header;
	union
	{
		PacketCopyMemory	 copy_memory;
		PacketGetBaseAddress get_base_address;
		PackedCompleted		 completed;
	} data;
};