/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    Wdffdo.h

Environment:

    user mode

NOTE: This header is generated by stubwork.

      To modify contents, add or remove <shared> or <umdf>
      tags in the corresponding .x and .y template files.

--*/

#pragma once

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START

typedef
_Function_class_(EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS(
    _In_
    WDFDEVICE Device,
    _In_
    WDFIORESREQLIST IoResourceRequirementsList
    );

typedef EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS *PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS;

typedef
_Function_class_(EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES(
    _In_
    WDFDEVICE Device,
    _In_
    WDFCMRESLIST ResourcesRaw,
    _In_
    WDFCMRESLIST ResourcesTranslated
    );

typedef EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES *PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES;

typedef struct _WDF_FDO_EVENT_CALLBACKS {
    //
    // Size of this structure in bytes
    //
    ULONG Size;

    PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterAddResourceRequirements;

    PFN_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtDeviceFilterRemoveResourceRequirements;

    PFN_WDF_DEVICE_REMOVE_ADDED_RESOURCES EvtDeviceRemoveAddedResources;

} WDF_FDO_EVENT_CALLBACKS, *PWDF_FDO_EVENT_CALLBACKS;

VOID
FORCEINLINE
WDF_FDO_EVENT_CALLBACKS_INIT(
    _Out_ PWDF_FDO_EVENT_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(WDF_FDO_EVENT_CALLBACKS));
    Callbacks->Size = sizeof(WDF_FDO_EVENT_CALLBACKS);
}


//
// WDF Function: WdfFdoInitOpenRegistryKey
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITOPENREGISTRYKEY)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    ULONG DeviceInstanceKeyType,
    _In_
    ACCESS_MASK DesiredAccess,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    _Out_
    WDFKEY* Key
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitOpenRegistryKey(
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    ULONG DeviceInstanceKeyType,
    _In_
    ACCESS_MASK DesiredAccess,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    _Out_
    WDFKEY* Key
    )
{
    return ((PFN_WDFFDOINITOPENREGISTRYKEY) WdfFunctions[WdfFdoInitOpenRegistryKeyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceInstanceKeyType, DesiredAccess, KeyAttributes, Key);
}


//
// WDF Function: WdfFdoInitQueryProperty
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITQUERYPROPERTY)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    _In_
    ULONG BufferLength,
    _Out_writes_bytes_all_opt_(BufferLength)
    PVOID PropertyBuffer,
    _Out_
    PULONG ResultLength
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitQueryProperty(
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    _In_
    ULONG BufferLength,
    _Out_writes_bytes_all_opt_(BufferLength)
    PVOID PropertyBuffer,
    _Out_
    PULONG ResultLength
    )
{
    return ((PFN_WDFFDOINITQUERYPROPERTY) WdfFunctions[WdfFdoInitQueryPropertyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, BufferLength, PropertyBuffer, ResultLength);
}


//
// WDF Function: WdfFdoInitAllocAndQueryProperty
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITALLOCANDQUERYPROPERTY)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    _In_
    _Strict_type_match_
    POOL_TYPE PoolType,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    _Out_
    WDFMEMORY* PropertyMemory
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitAllocAndQueryProperty(
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    DEVICE_REGISTRY_PROPERTY DeviceProperty,
    _In_
    _Strict_type_match_
    POOL_TYPE PoolType,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    _Out_
    WDFMEMORY* PropertyMemory
    )
{
    return ((PFN_WDFFDOINITALLOCANDQUERYPROPERTY) WdfFunctions[WdfFdoInitAllocAndQueryPropertyTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, PoolType, PropertyMemoryAttributes, PropertyMemory);
}


//
// WDF Function: WdfFdoInitQueryPropertyEx
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITQUERYPROPERTYEX)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
    _In_
    ULONG BufferLength,
    _Out_
    PVOID PropertyBuffer,
    _Out_
    PULONG ResultLength,
    _Out_
    PDEVPROPTYPE Type
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitQueryPropertyEx(
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
    _In_
    ULONG BufferLength,
    _Out_
    PVOID PropertyBuffer,
    _Out_
    PULONG ResultLength,
    _Out_
    PDEVPROPTYPE Type
    )
{
    return ((PFN_WDFFDOINITQUERYPROPERTYEX) WdfFunctions[WdfFdoInitQueryPropertyExTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, BufferLength, PropertyBuffer, ResultLength, Type);
}


//
// WDF Function: WdfFdoInitAllocAndQueryPropertyEx
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_WDFFDOINITALLOCANDQUERYPROPERTYEX)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
    _In_
    _Strict_type_match_
    POOL_TYPE PoolType,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    _Out_
    WDFMEMORY* PropertyMemory,
    _Out_
    PDEVPROPTYPE Type
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
WdfFdoInitAllocAndQueryPropertyEx(
    _In_
    PWDFDEVICE_INIT DeviceInit,
    _In_
    PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
    _In_
    _Strict_type_match_
    POOL_TYPE PoolType,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    _Out_
    WDFMEMORY* PropertyMemory,
    _Out_
    PDEVPROPTYPE Type
    )
{
    return ((PFN_WDFFDOINITALLOCANDQUERYPROPERTYEX) WdfFunctions[WdfFdoInitAllocAndQueryPropertyExTableIndex])(WdfDriverGlobals, DeviceInit, DeviceProperty, PoolType, PropertyMemoryAttributes, PropertyMemory, Type);
}


//
// WDF Function: WdfFdoInitSetFilter
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
VOID
(*PFN_WDFFDOINITSETFILTER)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    PWDFDEVICE_INIT DeviceInit
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
FORCEINLINE
WdfFdoInitSetFilter(
    _In_
    PWDFDEVICE_INIT DeviceInit
    )
{
    ((PFN_WDFFDOINITSETFILTER) WdfFunctions[WdfFdoInitSetFilterTableIndex])(WdfDriverGlobals, DeviceInit);
}

WDF_EXTERN_C_END
