#pragma once  // instruciton to preproessor or compiler - only include file once

void Log(const char *message);

// traditional way to prevent multiple include
#ifdef _LOG_H

#define _LOG_H
struct Player {};

#endif