/***************************************************************************************
* WinDriverBase
*
*     Blueprint windows driver
*
***************************************************************************************/

#include "ntddk.h"

/*-------------------------------------------------------------------------
  PROTOTYPES
--------------------------------------------------------------------------*/

extern "C"
NTSTATUS
DriverEntry
(
IN      PDRIVER_OBJECT              DriverObject,
IN      PUNICODE_STRING             RegistryPath
);

void
DriverUnload
(
IN      PDRIVER_OBJECT              DriverObject
);


/***************************************************************************************
	NAME:           DriverEntry
	DESCRIPTION:    Driver intialiation routine.

	ARGUMENTS:
		IN      PDRIVER_OBJECT          DriverObject
		Pointer to a DRIVER_OBJECT created for this driver.

		IN      PUNICODE_STRING         RegistryPath
			UNICODE_STRING which represents this drivers KEY in the Registry.

	IRQL:           IRQL_PASSIVE_LEVEL.

	RETURNS:        NTSTATUS
					STATUS_SUCCESS always
***************************************************************************************/
extern "C"
NTSTATUS
DriverEntry
(
IN      PDRIVER_OBJECT              DriverObject,
IN      PUNICODE_STRING             RegistryPath
)
{
	// register an unload routine
	DriverObject->DriverUnload = DriverUnload;

	DbgPrint("Driver Hello!\n");

	DbgPrint("Driver Path:     %ls\n", DriverObject->DriverName.Buffer);
	DbgPrint("Registry Entry:  %ls\n", RegistryPath->Buffer);

	return STATUS_SUCCESS;
}

/***************************************************************************************
	NAME:           DriverUnload
	DESCRIPTION:    Shutdown routine for the driver.

	ARGUMENTS:
		IN      PDRIVER_OBJECT          DriverObject
			Pointer to a DRIVER_OBJECT created for this driver.

	IRQL:           IRQL_PASSIVE_LEVEL.

	RETURNS:        None.
***************************************************************************************/
void
DriverUnload
(
IN      PDRIVER_OBJECT              DriverObject
)
{
	DbgPrint("Driver goodbye!");
}