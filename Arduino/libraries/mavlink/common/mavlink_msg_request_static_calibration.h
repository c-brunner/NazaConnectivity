// MESSAGE REQUEST_STATIC_CALIBRATION PACKING

#define MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION 68

typedef struct __mavlink_request_static_calibration_t
{
 uint16_t time; ///< The time to average over in ms
 uint8_t target_system; ///< The system which should auto-calibrate
 uint8_t target_component; ///< The system component which should auto-calibrate
} mavlink_request_static_calibration_t;

#define MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN 4
#define MAVLINK_MSG_ID_68_LEN 4

#define MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_CRC 32
#define MAVLINK_MSG_ID_68_CRC 32



#define MAVLINK_MESSAGE_INFO_REQUEST_STATIC_CALIBRATION { \
	"REQUEST_STATIC_CALIBRATION", \
	3, \
	{  { "time", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_request_static_calibration_t, time) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_request_static_calibration_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_request_static_calibration_t, target_component) }, \
         } \
}


/**
 * @brief Pack a request_static_calibration message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system The system which should auto-calibrate
 * @param target_component The system component which should auto-calibrate
 * @param time The time to average over in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_static_calibration_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN];
	_mav_put_uint16_t(buf, 0, time);
	_mav_put_uint8_t(buf, 2, target_system);
	_mav_put_uint8_t(buf, 3, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#else
	mavlink_request_static_calibration_t packet;
	packet.time = time;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif
}

/**
 * @brief Pack a request_static_calibration message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system The system which should auto-calibrate
 * @param target_component The system component which should auto-calibrate
 * @param time The time to average over in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_static_calibration_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN];
	_mav_put_uint16_t(buf, 0, time);
	_mav_put_uint8_t(buf, 2, target_system);
	_mav_put_uint8_t(buf, 3, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#else
	mavlink_request_static_calibration_t packet;
	packet.time = time;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif
}

/**
 * @brief Encode a request_static_calibration struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param request_static_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_static_calibration_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_request_static_calibration_t* request_static_calibration)
{
	return mavlink_msg_request_static_calibration_pack(system_id, component_id, msg, request_static_calibration->target_system, request_static_calibration->target_component, request_static_calibration->time);
}

/**
 * @brief Encode a request_static_calibration struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_static_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_static_calibration_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_request_static_calibration_t* request_static_calibration)
{
	return mavlink_msg_request_static_calibration_pack_chan(system_id, component_id, chan, msg, request_static_calibration->target_system, request_static_calibration->target_component, request_static_calibration->time);
}

/**
 * @brief Send a request_static_calibration message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system The system which should auto-calibrate
 * @param target_component The system component which should auto-calibrate
 * @param time The time to average over in ms
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_request_static_calibration_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN];
	_mav_put_uint16_t(buf, 0, time);
	_mav_put_uint8_t(buf, 2, target_system);
	_mav_put_uint8_t(buf, 3, target_component);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif
#else
	mavlink_request_static_calibration_t packet;
	packet.time = time;
	packet.target_system = target_system;
	packet.target_component = target_component;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, (const char *)&packet, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, (const char *)&packet, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_request_static_calibration_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, time);
	_mav_put_uint8_t(buf, 2, target_system);
	_mav_put_uint8_t(buf, 3, target_component);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif
#else
	mavlink_request_static_calibration_t *packet = (mavlink_request_static_calibration_t *)msgbuf;
	packet->time = time;
	packet->target_system = target_system;
	packet->target_component = target_component;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, (const char *)packet, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION, (const char *)packet, MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE REQUEST_STATIC_CALIBRATION UNPACKING


/**
 * @brief Get field target_system from request_static_calibration message
 *
 * @return The system which should auto-calibrate
 */
static inline uint8_t mavlink_msg_request_static_calibration_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from request_static_calibration message
 *
 * @return The system component which should auto-calibrate
 */
static inline uint8_t mavlink_msg_request_static_calibration_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field time from request_static_calibration message
 *
 * @return The time to average over in ms
 */
static inline uint16_t mavlink_msg_request_static_calibration_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a request_static_calibration message into a struct
 *
 * @param msg The message to decode
 * @param request_static_calibration C-struct to decode the message contents into
 */
static inline void mavlink_msg_request_static_calibration_decode(const mavlink_message_t* msg, mavlink_request_static_calibration_t* request_static_calibration)
{
#if MAVLINK_NEED_BYTE_SWAP
	request_static_calibration->time = mavlink_msg_request_static_calibration_get_time(msg);
	request_static_calibration->target_system = mavlink_msg_request_static_calibration_get_target_system(msg);
	request_static_calibration->target_component = mavlink_msg_request_static_calibration_get_target_component(msg);
#else
	memcpy(request_static_calibration, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_REQUEST_STATIC_CALIBRATION_LEN);
#endif
}
