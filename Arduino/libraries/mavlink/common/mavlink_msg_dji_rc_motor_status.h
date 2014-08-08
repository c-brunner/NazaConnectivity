// MESSAGE DJI_RC_MOTOR_STATUS PACKING

#define MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS 165

typedef struct __mavlink_dji_rc_motor_status_t
{
 int16_t rcA; ///< RC_A stick input (-1000~1000).
 int16_t rcE; ///< RC_E stick input (-1000~1000).
 int16_t rcR; ///< RC_R stick input (-1000~1000).
 int16_t rcU; ///< RC_U stick input (-1000~1000).
 int16_t rcT; ///< RC_T stick input (-1000~1000).
 int16_t rcX1; ///< RC_X1 stick input (-1000~1000).
 int16_t rcX2; ///< RC_X2 stick input (-1000~1000).
 uint16_t m1; ///< motor m1 output (16920~35000).
 uint16_t m2; ///< motor m2 output (16920~35000).
 uint16_t m3; ///< motor m3 output (16920~35000).
 uint16_t m4; ///< motor m4 output (16920~35000).
 uint16_t m5; ///< motor m5 output (16920~35000).
 uint16_t m6; ///< motor m6 output (16920~35000).
 uint16_t f1; ///< motor f1 output (16920~35000).
 uint16_t f2; ///< motor f2 output (16920~35000).
} mavlink_dji_rc_motor_status_t;

#define MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN 30
#define MAVLINK_MSG_ID_165_LEN 30

#define MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_CRC 223
#define MAVLINK_MSG_ID_165_CRC 223



#define MAVLINK_MESSAGE_INFO_DJI_RC_MOTOR_STATUS { \
	"DJI_RC_MOTOR_STATUS", \
	15, \
	{  { "rcA", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_dji_rc_motor_status_t, rcA) }, \
         { "rcE", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_dji_rc_motor_status_t, rcE) }, \
         { "rcR", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_dji_rc_motor_status_t, rcR) }, \
         { "rcU", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_dji_rc_motor_status_t, rcU) }, \
         { "rcT", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_dji_rc_motor_status_t, rcT) }, \
         { "rcX1", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_dji_rc_motor_status_t, rcX1) }, \
         { "rcX2", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_dji_rc_motor_status_t, rcX2) }, \
         { "m1", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_dji_rc_motor_status_t, m1) }, \
         { "m2", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_dji_rc_motor_status_t, m2) }, \
         { "m3", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_dji_rc_motor_status_t, m3) }, \
         { "m4", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_dji_rc_motor_status_t, m4) }, \
         { "m5", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_dji_rc_motor_status_t, m5) }, \
         { "m6", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_dji_rc_motor_status_t, m6) }, \
         { "f1", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_dji_rc_motor_status_t, f1) }, \
         { "f2", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_dji_rc_motor_status_t, f2) }, \
         } \
}


/**
 * @brief Pack a dji_rc_motor_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rcA RC_A stick input (-1000~1000).
 * @param rcE RC_E stick input (-1000~1000).
 * @param rcR RC_R stick input (-1000~1000).
 * @param rcU RC_U stick input (-1000~1000).
 * @param rcT RC_T stick input (-1000~1000).
 * @param rcX1 RC_X1 stick input (-1000~1000).
 * @param rcX2 RC_X2 stick input (-1000~1000).
 * @param m1 motor m1 output (16920~35000).
 * @param m2 motor m2 output (16920~35000).
 * @param m3 motor m3 output (16920~35000).
 * @param m4 motor m4 output (16920~35000).
 * @param m5 motor m5 output (16920~35000).
 * @param m6 motor m6 output (16920~35000).
 * @param f1 motor f1 output (16920~35000).
 * @param f2 motor f2 output (16920~35000).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t rcA, int16_t rcE, int16_t rcR, int16_t rcU, int16_t rcT, int16_t rcX1, int16_t rcX2, uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4, uint16_t m5, uint16_t m6, uint16_t f1, uint16_t f2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN];
	_mav_put_int16_t(buf, 0, rcA);
	_mav_put_int16_t(buf, 2, rcE);
	_mav_put_int16_t(buf, 4, rcR);
	_mav_put_int16_t(buf, 6, rcU);
	_mav_put_int16_t(buf, 8, rcT);
	_mav_put_int16_t(buf, 10, rcX1);
	_mav_put_int16_t(buf, 12, rcX2);
	_mav_put_uint16_t(buf, 14, m1);
	_mav_put_uint16_t(buf, 16, m2);
	_mav_put_uint16_t(buf, 18, m3);
	_mav_put_uint16_t(buf, 20, m4);
	_mav_put_uint16_t(buf, 22, m5);
	_mav_put_uint16_t(buf, 24, m6);
	_mav_put_uint16_t(buf, 26, f1);
	_mav_put_uint16_t(buf, 28, f2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#else
	mavlink_dji_rc_motor_status_t packet;
	packet.rcA = rcA;
	packet.rcE = rcE;
	packet.rcR = rcR;
	packet.rcU = rcU;
	packet.rcT = rcT;
	packet.rcX1 = rcX1;
	packet.rcX2 = rcX2;
	packet.m1 = m1;
	packet.m2 = m2;
	packet.m3 = m3;
	packet.m4 = m4;
	packet.m5 = m5;
	packet.m6 = m6;
	packet.f1 = f1;
	packet.f2 = f2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif
}

/**
 * @brief Pack a dji_rc_motor_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rcA RC_A stick input (-1000~1000).
 * @param rcE RC_E stick input (-1000~1000).
 * @param rcR RC_R stick input (-1000~1000).
 * @param rcU RC_U stick input (-1000~1000).
 * @param rcT RC_T stick input (-1000~1000).
 * @param rcX1 RC_X1 stick input (-1000~1000).
 * @param rcX2 RC_X2 stick input (-1000~1000).
 * @param m1 motor m1 output (16920~35000).
 * @param m2 motor m2 output (16920~35000).
 * @param m3 motor m3 output (16920~35000).
 * @param m4 motor m4 output (16920~35000).
 * @param m5 motor m5 output (16920~35000).
 * @param m6 motor m6 output (16920~35000).
 * @param f1 motor f1 output (16920~35000).
 * @param f2 motor f2 output (16920~35000).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t rcA,int16_t rcE,int16_t rcR,int16_t rcU,int16_t rcT,int16_t rcX1,int16_t rcX2,uint16_t m1,uint16_t m2,uint16_t m3,uint16_t m4,uint16_t m5,uint16_t m6,uint16_t f1,uint16_t f2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN];
	_mav_put_int16_t(buf, 0, rcA);
	_mav_put_int16_t(buf, 2, rcE);
	_mav_put_int16_t(buf, 4, rcR);
	_mav_put_int16_t(buf, 6, rcU);
	_mav_put_int16_t(buf, 8, rcT);
	_mav_put_int16_t(buf, 10, rcX1);
	_mav_put_int16_t(buf, 12, rcX2);
	_mav_put_uint16_t(buf, 14, m1);
	_mav_put_uint16_t(buf, 16, m2);
	_mav_put_uint16_t(buf, 18, m3);
	_mav_put_uint16_t(buf, 20, m4);
	_mav_put_uint16_t(buf, 22, m5);
	_mav_put_uint16_t(buf, 24, m6);
	_mav_put_uint16_t(buf, 26, f1);
	_mav_put_uint16_t(buf, 28, f2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#else
	mavlink_dji_rc_motor_status_t packet;
	packet.rcA = rcA;
	packet.rcE = rcE;
	packet.rcR = rcR;
	packet.rcU = rcU;
	packet.rcT = rcT;
	packet.rcX1 = rcX1;
	packet.rcX2 = rcX2;
	packet.m1 = m1;
	packet.m2 = m2;
	packet.m3 = m3;
	packet.m4 = m4;
	packet.m5 = m5;
	packet.m6 = m6;
	packet.f1 = f1;
	packet.f2 = f2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif
}

/**
 * @brief Encode a dji_rc_motor_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dji_rc_motor_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dji_rc_motor_status_t* dji_rc_motor_status)
{
	return mavlink_msg_dji_rc_motor_status_pack(system_id, component_id, msg, dji_rc_motor_status->rcA, dji_rc_motor_status->rcE, dji_rc_motor_status->rcR, dji_rc_motor_status->rcU, dji_rc_motor_status->rcT, dji_rc_motor_status->rcX1, dji_rc_motor_status->rcX2, dji_rc_motor_status->m1, dji_rc_motor_status->m2, dji_rc_motor_status->m3, dji_rc_motor_status->m4, dji_rc_motor_status->m5, dji_rc_motor_status->m6, dji_rc_motor_status->f1, dji_rc_motor_status->f2);
}

/**
 * @brief Encode a dji_rc_motor_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dji_rc_motor_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dji_rc_motor_status_t* dji_rc_motor_status)
{
	return mavlink_msg_dji_rc_motor_status_pack_chan(system_id, component_id, chan, msg, dji_rc_motor_status->rcA, dji_rc_motor_status->rcE, dji_rc_motor_status->rcR, dji_rc_motor_status->rcU, dji_rc_motor_status->rcT, dji_rc_motor_status->rcX1, dji_rc_motor_status->rcX2, dji_rc_motor_status->m1, dji_rc_motor_status->m2, dji_rc_motor_status->m3, dji_rc_motor_status->m4, dji_rc_motor_status->m5, dji_rc_motor_status->m6, dji_rc_motor_status->f1, dji_rc_motor_status->f2);
}

/**
 * @brief Send a dji_rc_motor_status message
 * @param chan MAVLink channel to send the message
 *
 * @param rcA RC_A stick input (-1000~1000).
 * @param rcE RC_E stick input (-1000~1000).
 * @param rcR RC_R stick input (-1000~1000).
 * @param rcU RC_U stick input (-1000~1000).
 * @param rcT RC_T stick input (-1000~1000).
 * @param rcX1 RC_X1 stick input (-1000~1000).
 * @param rcX2 RC_X2 stick input (-1000~1000).
 * @param m1 motor m1 output (16920~35000).
 * @param m2 motor m2 output (16920~35000).
 * @param m3 motor m3 output (16920~35000).
 * @param m4 motor m4 output (16920~35000).
 * @param m5 motor m5 output (16920~35000).
 * @param m6 motor m6 output (16920~35000).
 * @param f1 motor f1 output (16920~35000).
 * @param f2 motor f2 output (16920~35000).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dji_rc_motor_status_send(mavlink_channel_t chan, int16_t rcA, int16_t rcE, int16_t rcR, int16_t rcU, int16_t rcT, int16_t rcX1, int16_t rcX2, uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4, uint16_t m5, uint16_t m6, uint16_t f1, uint16_t f2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN];
	_mav_put_int16_t(buf, 0, rcA);
	_mav_put_int16_t(buf, 2, rcE);
	_mav_put_int16_t(buf, 4, rcR);
	_mav_put_int16_t(buf, 6, rcU);
	_mav_put_int16_t(buf, 8, rcT);
	_mav_put_int16_t(buf, 10, rcX1);
	_mav_put_int16_t(buf, 12, rcX2);
	_mav_put_uint16_t(buf, 14, m1);
	_mav_put_uint16_t(buf, 16, m2);
	_mav_put_uint16_t(buf, 18, m3);
	_mav_put_uint16_t(buf, 20, m4);
	_mav_put_uint16_t(buf, 22, m5);
	_mav_put_uint16_t(buf, 24, m6);
	_mav_put_uint16_t(buf, 26, f1);
	_mav_put_uint16_t(buf, 28, f2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, buf, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, buf, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif
#else
	mavlink_dji_rc_motor_status_t packet;
	packet.rcA = rcA;
	packet.rcE = rcE;
	packet.rcR = rcR;
	packet.rcU = rcU;
	packet.rcT = rcT;
	packet.rcX1 = rcX1;
	packet.rcX2 = rcX2;
	packet.m1 = m1;
	packet.m2 = m2;
	packet.m3 = m3;
	packet.m4 = m4;
	packet.m5 = m5;
	packet.m6 = m6;
	packet.f1 = f1;
	packet.f2 = f2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, (const char *)&packet, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, (const char *)&packet, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dji_rc_motor_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t rcA, int16_t rcE, int16_t rcR, int16_t rcU, int16_t rcT, int16_t rcX1, int16_t rcX2, uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4, uint16_t m5, uint16_t m6, uint16_t f1, uint16_t f2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int16_t(buf, 0, rcA);
	_mav_put_int16_t(buf, 2, rcE);
	_mav_put_int16_t(buf, 4, rcR);
	_mav_put_int16_t(buf, 6, rcU);
	_mav_put_int16_t(buf, 8, rcT);
	_mav_put_int16_t(buf, 10, rcX1);
	_mav_put_int16_t(buf, 12, rcX2);
	_mav_put_uint16_t(buf, 14, m1);
	_mav_put_uint16_t(buf, 16, m2);
	_mav_put_uint16_t(buf, 18, m3);
	_mav_put_uint16_t(buf, 20, m4);
	_mav_put_uint16_t(buf, 22, m5);
	_mav_put_uint16_t(buf, 24, m6);
	_mav_put_uint16_t(buf, 26, f1);
	_mav_put_uint16_t(buf, 28, f2);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, buf, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, buf, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif
#else
	mavlink_dji_rc_motor_status_t *packet = (mavlink_dji_rc_motor_status_t *)msgbuf;
	packet->rcA = rcA;
	packet->rcE = rcE;
	packet->rcR = rcR;
	packet->rcU = rcU;
	packet->rcT = rcT;
	packet->rcX1 = rcX1;
	packet->rcX2 = rcX2;
	packet->m1 = m1;
	packet->m2 = m2;
	packet->m3 = m3;
	packet->m4 = m4;
	packet->m5 = m5;
	packet->m6 = m6;
	packet->f1 = f1;
	packet->f2 = f2;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, (const char *)packet, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS, (const char *)packet, MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE DJI_RC_MOTOR_STATUS UNPACKING


/**
 * @brief Get field rcA from dji_rc_motor_status message
 *
 * @return RC_A stick input (-1000~1000).
 */
static inline int16_t mavlink_msg_dji_rc_motor_status_get_rcA(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field rcE from dji_rc_motor_status message
 *
 * @return RC_E stick input (-1000~1000).
 */
static inline int16_t mavlink_msg_dji_rc_motor_status_get_rcE(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field rcR from dji_rc_motor_status message
 *
 * @return RC_R stick input (-1000~1000).
 */
static inline int16_t mavlink_msg_dji_rc_motor_status_get_rcR(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field rcU from dji_rc_motor_status message
 *
 * @return RC_U stick input (-1000~1000).
 */
static inline int16_t mavlink_msg_dji_rc_motor_status_get_rcU(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field rcT from dji_rc_motor_status message
 *
 * @return RC_T stick input (-1000~1000).
 */
static inline int16_t mavlink_msg_dji_rc_motor_status_get_rcT(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field rcX1 from dji_rc_motor_status message
 *
 * @return RC_X1 stick input (-1000~1000).
 */
static inline int16_t mavlink_msg_dji_rc_motor_status_get_rcX1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field rcX2 from dji_rc_motor_status message
 *
 * @return RC_X2 stick input (-1000~1000).
 */
static inline int16_t mavlink_msg_dji_rc_motor_status_get_rcX2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field m1 from dji_rc_motor_status message
 *
 * @return motor m1 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_m1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field m2 from dji_rc_motor_status message
 *
 * @return motor m2 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_m2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field m3 from dji_rc_motor_status message
 *
 * @return motor m3 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_m3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field m4 from dji_rc_motor_status message
 *
 * @return motor m4 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_m4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field m5 from dji_rc_motor_status message
 *
 * @return motor m5 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_m5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field m6 from dji_rc_motor_status message
 *
 * @return motor m6 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_m6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field f1 from dji_rc_motor_status message
 *
 * @return motor f1 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_f1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field f2 from dji_rc_motor_status message
 *
 * @return motor f2 output (16920~35000).
 */
static inline uint16_t mavlink_msg_dji_rc_motor_status_get_f2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Decode a dji_rc_motor_status message into a struct
 *
 * @param msg The message to decode
 * @param dji_rc_motor_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_dji_rc_motor_status_decode(const mavlink_message_t* msg, mavlink_dji_rc_motor_status_t* dji_rc_motor_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	dji_rc_motor_status->rcA = mavlink_msg_dji_rc_motor_status_get_rcA(msg);
	dji_rc_motor_status->rcE = mavlink_msg_dji_rc_motor_status_get_rcE(msg);
	dji_rc_motor_status->rcR = mavlink_msg_dji_rc_motor_status_get_rcR(msg);
	dji_rc_motor_status->rcU = mavlink_msg_dji_rc_motor_status_get_rcU(msg);
	dji_rc_motor_status->rcT = mavlink_msg_dji_rc_motor_status_get_rcT(msg);
	dji_rc_motor_status->rcX1 = mavlink_msg_dji_rc_motor_status_get_rcX1(msg);
	dji_rc_motor_status->rcX2 = mavlink_msg_dji_rc_motor_status_get_rcX2(msg);
	dji_rc_motor_status->m1 = mavlink_msg_dji_rc_motor_status_get_m1(msg);
	dji_rc_motor_status->m2 = mavlink_msg_dji_rc_motor_status_get_m2(msg);
	dji_rc_motor_status->m3 = mavlink_msg_dji_rc_motor_status_get_m3(msg);
	dji_rc_motor_status->m4 = mavlink_msg_dji_rc_motor_status_get_m4(msg);
	dji_rc_motor_status->m5 = mavlink_msg_dji_rc_motor_status_get_m5(msg);
	dji_rc_motor_status->m6 = mavlink_msg_dji_rc_motor_status_get_m6(msg);
	dji_rc_motor_status->f1 = mavlink_msg_dji_rc_motor_status_get_f1(msg);
	dji_rc_motor_status->f2 = mavlink_msg_dji_rc_motor_status_get_f2(msg);
#else
	memcpy(dji_rc_motor_status, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_DJI_RC_MOTOR_STATUS_LEN);
#endif
}
