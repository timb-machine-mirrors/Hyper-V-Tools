#pragma once
#ifndef SHARED_STRUCTS_H
#define SHARED_STRUCTS_H

//#include "common.h"

// IOCTL codes for driver communication
#define IOCTL_HYPERV_CHECK_HYPERCALL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_HYPERV_CHECK_MSR       CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_HYPERV_CHECK_VMBUS     CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Hyper-V MSR constants
#define HV_X64_MSR_GUEST_OS_ID      0x40000000
#define HV_X64_MSR_HYPERCALL        0x40000001
#define HV_X64_MSR_VP_INDEX         0x40000002
#define HV_X64_MSR_RESET            0x40000003
#define HV_X64_MSR_VP_RUNTIME       0x40000010

// Hypercall codes
#define HVCALL_POST_MESSAGE         0x005C
#define HVCALL_SIGNAL_EVENT         0x005D
#define HVCALL_GET_PARTITION_ID     0x0046
#define HVCALL_GET_VP_REGISTERS     0x0050

typedef struct _HYPERCALL_INPUT {
    DWORD HypercallCode;
    DWORD InputParamCount;
    DWORD OutputParamCount;
} HYPERCALL_INPUT, *PHYPERCALL_INPUT;

typedef struct _HYPERCALL_OUTPUT {
    DWORD Result;
    DWORD OutputValue;
} HYPERCALL_OUTPUT, *PHYPERCALL_OUTPUT;

typedef struct _MSR_INPUT {
    DWORD MsrIndex;
} MSR_INPUT, *PMSR_INPUT;

typedef struct _MSR_OUTPUT {
    DWORD Result;
    ULONGLONG Value;
} MSR_OUTPUT, *PMSR_OUTPUT;

#endif // SHARED_STRUCTS_H