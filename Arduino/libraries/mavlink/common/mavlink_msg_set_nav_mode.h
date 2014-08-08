// MESSAGE SET_NAV_MODE PACKING

#define MAVLINK_MSG_ID_SET_NAV_MODE 12

typedef struct __mavlink_set_nav_mode_t
{
 uint8_t target; ///< The system setting the mode
 uint8_t nav_mode; ///< The new navigation mode
} mavlink_set_nav_mode_t;

#define MAVLINK_MSG_ID_SET_NAV_MODE_LEN 2
#define MAVLINK_MSG_ID_12_LEN 2

#define MAVLINK_MSG_ID_SET_NAV_MODE_CRC 10
#define MAVLINK_MSG_ID_12_CRC 10



#define MAVLINK_MESSAGE_INFO_SET_NAV_MODE { \
	"SET_NAV_MODE", \
	2, \
	{  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_nav_mode_t, target) }, \
         { "nav_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_set_nav_mode_t, nav_mode) }, \
         } \
}


/**
 * @brief Pack a set_nav_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target The system setting the mode
 * @param nav_mode The new navigation mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_nav_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target, uint8_t nav_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_NAV_MODE_LEN];
	_mav_put_uint8_t(buf, 0, target);
	_mav_put_uint8_t(buf, 1, nav_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#else
	mavlink_set_nav_mode_t packet;
	packet.target = target;
	packet.nav_mode = nav_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_NAV_MODE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_NAV_MODE_LEN, MAVLINK_MSG_ID_SET_NAV_MODE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif
}

/**
 * @brief Pack a set_nav_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system setting the mode
 * @param nav_mode The new navigation mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_nav_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target,uint8_t nav_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_NAV_MODE_LEN];
	_mav_put_uint8_t(buf, 0, target);
	_mav_put_uint8_t(buf, 1, nav_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#else
	mavlink_set_nav_mode_t packet;
	packet.target = target;
	packet.nav_mode = nav_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_NAV_MODE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_NAV_MODE_LEN, MAVLINK_MSG_ID_SET_NAV_MODE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif
}

/**
 * @brief Encode a set_nav_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_nav_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_nav_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_nav_mode_t* set_nav_mode)
{
	return mavlink_msg_set_nav_mode_pack(system_id, component_id, msg, set_nav_mode->target, set_nav_mode->nav_mode);
}

/**
 * @brief Encode a set_nav_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_nav_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_nav_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_nav_mode_t* set_nav_mode)
{
	return mavlink_msg_set_nav_mode_pack_chan(system_id, component_id, chan, msg, set_nav_mode->target, set_nav_mode->nav_mode);
}

/**
 * @brief Send a set_nav_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param target The system setting the mode
 * @param nav_mode The new navigation mode
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_nav_mode_send(mavlink_channel_t chan, uint8_t target, uint8_t nav_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_NAV_MODE_LEN];
	_mav_put_uint8_t(buf, 0, target);
	_mav_put_uint8_t(buf, 1, nav_mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, buf, MAVLINK_MSG_ID_SET_NAV_MODE_LEN, MAVLINK_MSG_ID_SET_NAV_MODE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, buf, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif
#else
	mavlink_set_nav_mode_t packet;
	packet.target = target;
	packet.nav_mode = nav_mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, (const char *)&packet, MAVLINK_MSG_ID_SET_NAV_MODE_LEN, MAVLINK_MSG_ID_SET_NAV_MODE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, (const char *)&packet, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SET_NAV_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_nav_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target, uint8_t nav_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target);
	_mav_put_uint8_t(buf, 1, nav_mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, buf, MAVLINK_MSG_ID_SET_NAV_MODE_LEN, MAVLINK_MSG_ID_SET_NAV_MODE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, buf, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif
#else
	mavlink_set_nav_mode_t *packet = (mavlink_set_nav_mode_t *)msgbuf;
	packet->target = target;
	packet->nav_mode = nav_mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, (const char *)packet, MAVLINK_MSG_ID_SET_NAV_MODE_LEN, MAVLINK_MSG_ID_SET_NAV_MODE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_NAV_MODE, (const char *)packet, MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SET_NAV_MODE UNPACKING


/**
 * @brief Get field target from set_nav_mode message
 *
 * @return The system setting the mode
 */
static inline uint8_t mavlink_msg_set_nav_mode_get_target(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field nav_mode from set_nav_mode message
 *
 * @return The new navigation mode
 */
static inline uint8_t mavlink_msg_set_nav_mode_get_nav_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a set_nav_mode message into a struct
 *
 * @param msg The message to decode
 * @param set_nav_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_nav_mode_decode(const mavlink_message_t* msg, mavlink_set_nav_mode_t* set_nav_mode)
{
#if MAVLINK_NEED_BYTE_SWAP
	set_nav_mode->target = mavlink_msg_set_nav_mode_get_target(msg);
	set_nav_mode->nav_mode = mavlink_msg_set_nav_mode_get_nav_mode(msg);
#else
	memcpy(set_nav_mode, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SET_NAV_MODE_LEN);
#endif
}
