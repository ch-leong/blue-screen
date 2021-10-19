#include <Windows.h>

#pragma comment(lib, "ntdll.lib")

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG privilege, BOOLEAN enable, BOOLEAN currThread, PBOOLEAN statusPointer);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG errorStatus, ULONG unless1, ULONG unless2, PULONG_PTR unless3, ULONG validResponseOption, PULONG responsePointer);

int main()
{
  BOOLEAN privilegeState = FALSE;
  RtlAdjustPrivilege(19, TRUE, FALSE, &privilegeState);

  ULONG errorResponse = 0;
  NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &errorResponse);
  return 0;
}
