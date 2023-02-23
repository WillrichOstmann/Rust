#pragma once

template <typename... Args>
void log(const char* format, Args... args)
{
	DbgPrintEx(0, 0, "[debugz] ");
	DbgPrintEx(0, 0, format, args...);
	DbgPrintEx(0, 0, "\n");
}