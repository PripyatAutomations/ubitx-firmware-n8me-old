#pragma once
// These allow selecting a license class of the user below
// This merely shows the lower and upper bounds of the band
// For that privilege level. It does NOT prevent you from
// TXing outside your allowed modes or frequencies.
// No plans exist to add such functionality. It's just a helpful hint onscreen
#define	BANDPLAN_DEFAULT	0x00

#define	PRIV_NONE	0x00		// RX only
#define	PRIV_CW	0x01		// TX CW
#define	PRIV_RTTY	0x02		// TX RTTY
#define	PRIV_SSB	0x04		// TX SSB Voice
#define	PRIV_DIGITAL	0x08		// TX Data (digital) modes
#define	PRIV_IMAGE	0x10		// TX Images
#define	PRIV_PHONE	0x20		// TX Phone (AM) voice
#define	PRIV_DATA	(PRIV_CW|PRIV_DIGITAL|PRIV_RTTY)
#define	PRIV_VOICE	(PRIV_CW|PRIV_SSB|PRIV_PHONE)
#define	PRIV_ALL	(PRIV_DATA|PRIV_VOICE|PRIV_IMAGE)

struct __attribute__((__packed__)) Bandplan {
   const char	Name[5];
   uint8_t	Meters;
   uint32_t	Start;
   uint32_t	End;
   uint16_t	Privileges;
};
typedef struct Bandplan Bandplan;

// This is brought in via bandplan.cc from various bandplan_CC.h files
// Feel free to contribute bandplans for other regions!
extern const Bandplan User_Bandplan[] PROGMEM;
