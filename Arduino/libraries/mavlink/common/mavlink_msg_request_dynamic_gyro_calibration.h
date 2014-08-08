// MESSAGE REQUEST_DYNAMIC_GYRO_CALIBRATION PACKING

#define MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION 67

typedef struct __mavlink_request_dynamic_gyro_calibration_t
{
 float mode; ///< The current ground-truth rpm
 uint16_t time; ///< The time to average over in ms
 uint8_t target_system; ///< The system which should auto-calibrate
 uint8_t target_component; ///< The system component which should auto-calibrate
 uint8_t axis; ///< The axis to calibrate: 0 roll, 1 pitch, 2 yaw
} mavlink_request_dynamic_gyro_calibration_t;

#define MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN 9
#define MAVLINK_MSG_ID_67_LEN 9

#define MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_CRC 168
#define MAVLINK_MSG_ID_67_CRC 168



#define MAVLINK_MESSAGE_INFO_REQUEST_DYNAMIC_GYRO_CALIBRATION { \
	"REQUEST_DYNAMIC_GYRO_CALIBRATION", \
	5, \
	{  { "mode", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_request_dynamic_gyro_calibration_t, mode) }, \
         { "time", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_request_dynamic_gyro_calibration_t, time) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_request_dynamic_gyro_calibration_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_request_dynamic_gyro_calibration_t, target_component) }, \
         { "axis", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_request_dynamic_gyro_calibration_t, axis) }, \
         } \
}


/**
 * @brief Pack a request_dynamic_gyro_calibration message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system The system which should auto-calibrate
 * @param target_component The system component which should auto-calibrate
 * @param mode The current ground-truth rpm
 * @param axis The axis to calibrate: 0 roll, 1 pitch, 2 yaw
 * @param time The time to average over in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_dynamic_gyro_calibration_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, float mode, uint8_t axis, uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN];
	_mav_put_float(buf, 0, mode);
	_mav_put_uint16_t(buf, 4, time);
	_mav_put_uint8_t(buf, 6, target_system);
	_mav_put_uint8_t(buf, 7, target_component);
	_mav_put_uint8_t(buf, 8, axis);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#else
	mavlink_request_dynamic_gyro_calibration_t packet;
	packet.mode = mode;
	packet.time = time;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.axis = axis;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif
}

/**
 * @brief Pack a request_dynamic_gyro_calibration message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system The system which should auto-calibrate
 * @param target_component The system component which should auto-calibrate
 * @param mode The current ground-truth rpm
 * @param axis The axis to calibrate: 0 roll, 1 pitch, 2 yaw
 * @param time The time to average over in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_dynamic_gyro_calibration_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,float mode,uint8_t axis,uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN];
	_mav_put_float(buf, 0, mode);
	_mav_put_uint16_t(buf, 4, time);
	_mav_put_uint8_t(buf, 6, target_system);
	_mav_put_uint8_t(buf, 7, target_component);
	_mav_put_uint8_t(buf, 8, axis);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#else
	mavlink_request_dynamic_gyro_calibration_t packet;
	packet.mode = mode;
	packet.time = time;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.axis = axis;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif
}

/**
 * @brief Encode a request_dynamic_gyro_calibration struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param request_dynamic_gyro_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_dynamic_gyro_calibration_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_request_dynamic_gyro_calibration_t* request_dynamic_gyro_calibration)
{
	return mavlink_msg_request_dynamic_gyro_calibration_pack(system_id, component_id, msg, request_dynamic_gyro_calibration->target_system, request_dynamic_gyro_calibration->target_component, request_dynamic_gyro_calibration->mode, request_dynamic_gyro_calibration->axis, request_dynamic_gyro_calibration->time);
}

/**
 * @brief Encode a request_dynamic_gyro_calibration struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_dynamic_gyro_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_dynamic_gyro_calibration_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_request_dynamic_gyro_calibration_t* request_dynamic_gyro_calibration)
{
	return mavlink_msg_request_dynamic_gyro_calibration_pack_chan(system_id, component_id, chan, msg, request_dynamic_gyro_calibration->target_system, request_dynamic_gyro_calibration->target_component, request_dynamic_gyro_calibration->mode, request_dynamic_gyro_calibration->axis, request_dynamic_gyro_calibration->time);
}

/**
 * @brief Send a request_dynamic_gyro_calibration message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system The system which should auto-calibrate
 * @param target_component The system component which should auto-calibrate
 * @param mode The current ground-truth rpm
 * @param axis The axis to calibrate: 0 roll, 1 pitch, 2 yaw
 * @param time The time to average over in ms
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_request_dynamic_gyro_calibration_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float mode, uint8_t axis, uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN];
	_mav_put_float(buf, 0, mode);
	_mav_put_uint16_t(buf, 4, time);
	_mav_put_uint8_t(buf, 6, target_system);
	_mav_put_uint8_t(buf, 7, target_component);
	_mav_put_uint8_t(buf, 8, axis);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif
#else
	mavlink_request_dynamic_gyro_calibration_t packet;
	packet.mode = mode;
	packet.time = time;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.axis = axis;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, (const char *)&packet, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, (const char *)&packet, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_request_dynamic_gyro_calibration_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, float mode, uint8_t axis, uint16_t time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, mode);
	_mav_put_uint16_t(buf, 4, time);
	_mav_put_uint8_t(buf, 6, target_system);
	_mav_put_uint8_t(buf, 7, target_component);
	_mav_put_uint8_t(buf, 8, axis);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, buf, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif
#else
	mavlink_request_dynamic_gyro_calibration_t *packet = (mavlink_request_dynamic_gyro_calibration_t *)msgbuf;
	packet->mode = mode;
	packet->time = time;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->axis = axis;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, (const char *)packet, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION, (const char *)packet, MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE REQUEST_DYNAMIC_GYRO_CALIBRATION UNPACKING


/**
 * @brief Get field target_system from request_dynamic_gyro_calibration message
 *
 * @return The system which should auto-calibrate
 */
static inline uint8_t mavlink_msg_request_dynamic_gyro_calibration_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field target_component from request_dynamic_gyro_calibration message
 *
 * @return The system component which should auto-calibrate
 */
static inline uint8_t mavlink_msg_request_dynamic_gyro_calibration_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field mode from request_dynamic_gyro_calibration message
 *
 * @return The current ground-truth rpm
 */
static inline float mavlink_msg_request_dynamic_gyro_calibration_get_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field axis from request_dynamic_gyro_calibration message
 *
 * @return The axis to calibrate: 0 roll, 1 pitch, 2 yaw
 */
static inline uint8_t mavlink_msg_request_dynamic_gyro_calibration_get_axis(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field time from request_dynamic_gyro_calibration message
 *
 * @return The time to average over in ms
 */
static inline uint16_t mavlink_msg_request_dynamic_gyro_calibration_get_time(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a request_dynamic_gyro_calibration message into a struct
 *
 * @param msg The message to decode
 * @param request_dynamic_gyro_calibration C-struct to decode the message contents into
 */
static inline void mavlink_msg_request_dynamic_gyro_calibration_decode(const mavlink_message_t* msg, mavlink_request_dynamic_gyro_calibration_t* request_dynamic_gyro_calibration)
{
#if MAVLINK_NEED_BYTE_SWAP
	request_dynamic_gyro_calibration->mode = mavlink_msg_request_dynamic_gyro_calibration_get_mode(msg);
	request_dynamic_gyro_calibration->time = mavlink_msg_request_dynamic_gyro_calibration_get_time(msg);
	request_dynamic_gyro_calibration->target_system = mavlink_msg_request_dynamic_gyro_calibration_get_target_system(msg);
	request_dynamic_gyro_calibration->target_component = mavlink_msg_request_dynamic_gyro_calibration_get_target_component(msg);
	request_dynamic_gyro_calibration->axis = mavlink_msg_request_dynamic_gyro_calibration_get_axis(msg);
#else
	memcpy(request_dynamic_gyro_calibration, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_REQUEST_DYNAMIC_GYRO_CALIBRATION_LEN);
#endif
}
