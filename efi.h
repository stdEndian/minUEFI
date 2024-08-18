#include <stdint.h>
//#include <uchar.h> ;)


typedef uint64_t UINTN;
typedef uint64_t UINT64;
typedef uint32_t UINT32;
typedef uint16_t UINT16;
typedef uint8_t  UINT8;

//typedef char16_t CHAR16;

typedef uint8_t  BOOLEAN;

typedef void VOID;

typedef UINTN EFI_STATUS;
typedef void* EFI_HANDLE;
typedef UINTN EFI_SUCCESS;

#define IN
#define OPTIONAL
#define EFIAPI __attribute__((ms_abi))

#define EFI_SUCCESS 0

#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x0
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F


#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50


#define EFI_TEXT_ATTR(Foreground,Background) \
((Foreground) | ((Background) << 4))


typedef struct {
  UINT64 Signature;
  UINT32 Revision;
  UINT32 HeaderSize;
  UINT32 CRC32;
  UINT32 Reserved;
} EFI_TABLE_HEADER;




/*
typedef struct _EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL {
  EFI_INPUT_RESET_EX Reset;
  EFI_INPUT_READ_KEY_EX ReadKeyStrokeEx;
  EFI_EVENT WaitForKeyEx;
  EFI_SET_STATE SetState;
  EFI_REGISTER_KEYSTROKE_NOTIFY RegisterKeyNotify;
  void* UnregisterKeyNotify;
} EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL;
*/


typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;


typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_STRING) (
			   IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
			   IN int16_t* String
);


typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_ATTRIBUTE) (
				  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
				  IN UINTN Attribute
);


typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_CLEAR_SCREEN) (
				  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This
);


typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) (
					IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
					IN UINTN Column,
					IN UINTN Row
);


typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_ENABLE_CURSOR) (
				  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
				  IN BOOLEAN Visible
);


typedef enum {
  EfiResetCold,
  EfiResetWarm,
  EfiResetShutdown,
  EfiResetPlatformSpecific
} EFI_RESET_TYPE;


typedef struct {
  UINT32 Data1;
  UINT16 Data2;
  UINT16 Data3;
  UINT8 Data4[8];
} EFI_GUID;


typedef struct{
  //EFI_GUID VendorGuid;
  void* VendorGuid;
  
  VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;


typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
  //EFI_TEXT_RESET Reset;
  void* Reset;
  
  EFI_TEXT_STRING OutputString;
  //EFI_TEXT_TEST_STRING TestString;
  void* TestString;
  
  //EFI_TEXT_QUERY_MODE QueryMode;
  void* QueryMode;
  
  //EFI_TEXT_SET_MODE SetMode;
  void* SetMode;
  
  EFI_TEXT_SET_ATTRIBUTE SetAttribute;
  EFI_TEXT_CLEAR_SCREEN ClearScreen;
  EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
  EFI_TEXT_ENABLE_CURSOR EnableCursor;

  //SIMPLE_TEXT_OUTPUT_MODE *Mode;
  void* Mode;
  
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;


typedef
VOID
(EFIAPI *EFI_RESET_SYSTEM) (
			     IN EFI_RESET_TYPE ResetType,
			     IN EFI_STATUS ResetStatus,
			     IN UINTN DataSize,
			     IN VOID *ResetData OPTIONAL
);


typedef struct {
  EFI_TABLE_HEADER Hdr;

  //EFI_GET_TIME GetTime;
  void* GetTime;

  //EFI_SET_TIME SetTime;
  void* SetTime;

  //EFI_GET_WAKEUP_TIME GetWakeupTime;
  void* GetWakeupTime;

  //EFI_SET_WAKEUP_TIME SetWakeupTime;
  void* SetWakeupTime;

  //EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
  void* SetVirtualAddressMap;

  //EFI_CONVERT_POINTER ConvertPointer;
  void* ConvertPointer;  

  //EFI_GET_VARIABLE GetVariable;
  void* GetVariable;

  //EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
  void* GetNextVariableName;

  //EFI_SET_VARIABLE SetVariable;
  void* SetVariable;

  //EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
  void* GetNextHighMonotonicCount;

  EFI_RESET_SYSTEM ResetSystem;

  //EFI_UPDATE_CAPSULE UpdateCapsule;
  void* UpdateCapsule;

  //EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
  void* QueryCapsuleCapabilities;

  //EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
  void* QueryVariableInfo;
} EFI_RUNTIME_SERVICES;


typedef struct {
  EFI_TABLE_HEADER Hdr;
  
  //CHAR16 *FirmwareVendor;
  void* FirmwareVendor;
  
  //UINT32 FirmwareRevision;
  void* FirmwareRevision;
  
  EFI_HANDLE ConsoleInHandle;
  //EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
  void* ConIn;
  
  EFI_HANDLE ConsoleOutHandle;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;

  EFI_HANDLE StandardErrorHandle;
  //EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
  void* StdErr;
  
  EFI_RUNTIME_SERVICES *RuntimeServices;
  
  //EFI_BOOT_SERVICES *BootServices;
  void* BootServices;
  
  UINTN NumberOfTableEntries;
  EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;
