#include "efi.h"

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
  (void)(ImageHandle);

  //SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_TEXT_ATTR(EFI_WHITE, EFI_BLACK));

  SystemTable->ConOut->OutputString(SystemTable->ConOut, (int16_t*)L"Hello LL?\n");

  return EFI_SUCCESS;
}
