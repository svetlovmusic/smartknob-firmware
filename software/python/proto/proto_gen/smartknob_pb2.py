# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: smartknob.proto
# Protobuf Python Version: 5.27.2
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import runtime_version as _runtime_version
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
_runtime_version.ValidateProtobufRuntimeVersion(
    _runtime_version.Domain.PUBLIC,
    5,
    27,
    2,
    '',
    'smartknob.proto'
)
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import nanopb_pb2 as nanopb__pb2
import settings_pb2 as settings__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x0fsmartknob.proto\x12\x02PB\x1a\x0cnanopb.proto\x1a\x0esettings.proto\"\x9a\x02\n\rFromSmartKnob\x12\x1f\n\x10protocol_version\x18\x01 \x01(\rB\x05\x92?\x02\x38\x08\x12\x18\n\x04knob\x18\x03 \x01(\x0b\x32\x08.PB.KnobH\x00\x12\x16\n\x03\x61\x63k\x18\x04 \x01(\x0b\x32\x07.PB.AckH\x00\x12\x16\n\x03log\x18\x05 \x01(\x0b\x32\x07.PB.LogH\x00\x12-\n\x0fsmartknob_state\x18\x06 \x01(\x0b\x32\x12.PB.SmartKnobStateH\x00\x12\x30\n\x11motor_calib_state\x18\x07 \x01(\x0b\x32\x13.PB.MotorCalibStateH\x00\x12\x32\n\x12strain_calib_state\x18\x08 \x01(\x0b\x32\x14.PB.StrainCalibStateH\x00\x42\t\n\x07payload\"\xb4\x02\n\x0bToSmartknob\x12\x1f\n\x10protocol_version\x18\x01 \x01(\rB\x05\x92?\x02\x38\x08\x12\r\n\x05nonce\x18\x02 \x01(\r\x12)\n\rrequest_state\x18\x03 \x01(\x0b\x32\x10.PB.RequestStateH\x00\x12/\n\x10smartknob_config\x18\x04 \x01(\x0b\x32\x13.PB.SmartKnobConfigH\x00\x12\x31\n\x11smartknob_command\x18\x05 \x01(\x0e\x32\x14.PB.SmartKnobCommandH\x00\x12\x33\n\x12strain_calibration\x18\x06 \x01(\x0b\x32\x15.PB.StrainCalibrationH\x00\x12&\n\x08settings\x18\x07 \x01(\x0b\x32\x12.SETTINGS.SettingsH\x00\x42\t\n\x07payload\"\x9b\x01\n\x04Knob\x12\x1a\n\x0bmac_address\x18\x01 \x01(\tB\x05\x92?\x02p2\x12\x19\n\nip_address\x18\x02 \x01(\tB\x05\x92?\x02p2\x12\x36\n\x11persistent_config\x18\x03 \x01(\x0b\x32\x1b.PB.PersistentConfiguration\x12$\n\x08settings\x18\x04 \x01(\x0b\x32\x12.SETTINGS.Settings\"%\n\x0fMotorCalibState\x12\x12\n\ncalibrated\x18\x01 \x01(\x08\"6\n\x10StrainCalibState\x12\x0c\n\x04step\x18\x01 \x01(\r\x12\x14\n\x0cstrain_scale\x18\x02 \x01(\x02\"\x14\n\x03\x41\x63k\x12\r\n\x05nonce\x18\x01 \x01(\r\"b\n\x03Log\x12\x13\n\x03msg\x18\x01 \x01(\tB\x06\x92?\x03p\xff\x01\x12\x1b\n\x05level\x18\x02 \x01(\x0e\x32\x0c.PB.LogLevel\x12\x16\n\x06origin\x18\x03 \x01(\tB\x06\x92?\x03p\x80\x01\x12\x11\n\tisVerbose\x18\x04 \x01(\x08\"\x86\x01\n\x0eSmartKnobState\x12\x18\n\x10\x63urrent_position\x18\x01 \x01(\x05\x12\x19\n\x11sub_position_unit\x18\x02 \x01(\x02\x12#\n\x06\x63onfig\x18\x03 \x01(\x0b\x32\x13.PB.SmartKnobConfig\x12\x1a\n\x0bpress_nonce\x18\x04 \x01(\rB\x05\x92?\x02\x38\x08\"\xdf\x02\n\x0fSmartKnobConfig\x12\x10\n\x08position\x18\x01 \x01(\x05\x12\x19\n\x11sub_position_unit\x18\x02 \x01(\x02\x12\x1d\n\x0eposition_nonce\x18\x03 \x01(\rB\x05\x92?\x02\x38\x08\x12\x14\n\x0cmin_position\x18\x04 \x01(\x05\x12\x14\n\x0cmax_position\x18\x05 \x01(\x05\x12\x1e\n\x16position_width_radians\x18\x06 \x01(\x02\x12\x1c\n\x14\x64\x65tent_strength_unit\x18\x07 \x01(\x02\x12\x1d\n\x15\x65ndstop_strength_unit\x18\x08 \x01(\x02\x12\x12\n\nsnap_point\x18\t \x01(\x02\x12\x11\n\x02id\x18\n \x01(\tB\x05\x92?\x02p@\x12\x1f\n\x10\x64\x65tent_positions\x18\x0b \x03(\x05\x42\x05\x92?\x02\x10\x05\x12\x17\n\x0fsnap_point_bias\x18\x0c \x01(\x02\x12\x16\n\x07led_hue\x18\r \x01(\x05\x42\x05\x92?\x02\x38\x10\"\x0e\n\x0cRequestState\"e\n\x17PersistentConfiguration\x12\x0f\n\x07version\x18\x01 \x01(\r\x12#\n\x05motor\x18\x02 \x01(\x0b\x32\x14.PB.MotorCalibration\x12\x14\n\x0cstrain_scale\x18\x03 \x01(\x02\"p\n\x10MotorCalibration\x12\x12\n\ncalibrated\x18\x01 \x01(\x08\x12\x1e\n\x16zero_electrical_offset\x18\x02 \x01(\x02\x12\x14\n\x0c\x64irection_cw\x18\x03 \x01(\x08\x12\x12\n\npole_pairs\x18\x04 \x01(\r\"8\n\x0bStrainState\x12\x14\n\x0cpress_weight\x18\x01 \x01(\x05\x12\x13\n\x0bpress_value\x18\x02 \x01(\x02\"/\n\x11StrainCalibration\x12\x1a\n\x12\x63\x61libration_weight\x18\x01 \x01(\x02\"\xf6\x01\n\rSpotifyConfig\x12\x0f\n\x07version\x18\x01 \x01(\r\x12$\n\x14\x62\x61se64_id_and_secret\x18\x02 \x01(\tB\x06\x92?\x03p\x80\x01\x12\x1c\n\x0c\x61\x63\x63\x65ss_token\x18\x03 \x01(\tB\x06\x92?\x03p\x80\x04\x12\x19\n\ntoken_type\x18\x04 \x01(\tB\x05\x92?\x02p@\x12\x15\n\x05scope\x18\x05 \x01(\tB\x06\x92?\x03p\x80\x01\x12\x12\n\nexpires_in\x18\x06 \x01(\r\x12\x1d\n\rrefresh_token\x18\x07 \x01(\tB\x06\x92?\x03p\x80\x04\x12\x11\n\ttimestamp\x18\x08 \x01(\x04\x12\x18\n\tdevice_id\x18\t \x01(\tB\x05\x92?\x02p@*D\n\x08LogLevel\x12\x08\n\x04INFO\x10\x00\x12\x0b\n\x07WARNING\x10\x01\x12\t\n\x05\x45RROR\x10\x02\x12\t\n\x05\x44\x45\x42UG\x10\x03\x12\x0b\n\x07VERBOSE\x10\x04*P\n\x10SmartKnobCommand\x12\x11\n\rGET_KNOB_INFO\x10\x00\x12\x13\n\x0fMOTOR_CALIBRATE\x10\x01\x12\x14\n\x10STRAIN_CALIBRATE\x10\x02\x62\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'smartknob_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  DESCRIPTOR._loaded_options = None
  _globals['_FROMSMARTKNOB'].fields_by_name['protocol_version']._loaded_options = None
  _globals['_FROMSMARTKNOB'].fields_by_name['protocol_version']._serialized_options = b'\222?\0028\010'
  _globals['_TOSMARTKNOB'].fields_by_name['protocol_version']._loaded_options = None
  _globals['_TOSMARTKNOB'].fields_by_name['protocol_version']._serialized_options = b'\222?\0028\010'
  _globals['_KNOB'].fields_by_name['mac_address']._loaded_options = None
  _globals['_KNOB'].fields_by_name['mac_address']._serialized_options = b'\222?\002p2'
  _globals['_KNOB'].fields_by_name['ip_address']._loaded_options = None
  _globals['_KNOB'].fields_by_name['ip_address']._serialized_options = b'\222?\002p2'
  _globals['_LOG'].fields_by_name['msg']._loaded_options = None
  _globals['_LOG'].fields_by_name['msg']._serialized_options = b'\222?\003p\377\001'
  _globals['_LOG'].fields_by_name['origin']._loaded_options = None
  _globals['_LOG'].fields_by_name['origin']._serialized_options = b'\222?\003p\200\001'
  _globals['_SMARTKNOBSTATE'].fields_by_name['press_nonce']._loaded_options = None
  _globals['_SMARTKNOBSTATE'].fields_by_name['press_nonce']._serialized_options = b'\222?\0028\010'
  _globals['_SMARTKNOBCONFIG'].fields_by_name['position_nonce']._loaded_options = None
  _globals['_SMARTKNOBCONFIG'].fields_by_name['position_nonce']._serialized_options = b'\222?\0028\010'
  _globals['_SMARTKNOBCONFIG'].fields_by_name['id']._loaded_options = None
  _globals['_SMARTKNOBCONFIG'].fields_by_name['id']._serialized_options = b'\222?\002p@'
  _globals['_SMARTKNOBCONFIG'].fields_by_name['detent_positions']._loaded_options = None
  _globals['_SMARTKNOBCONFIG'].fields_by_name['detent_positions']._serialized_options = b'\222?\002\020\005'
  _globals['_SMARTKNOBCONFIG'].fields_by_name['led_hue']._loaded_options = None
  _globals['_SMARTKNOBCONFIG'].fields_by_name['led_hue']._serialized_options = b'\222?\0028\020'
  _globals['_SPOTIFYCONFIG'].fields_by_name['base64_id_and_secret']._loaded_options = None
  _globals['_SPOTIFYCONFIG'].fields_by_name['base64_id_and_secret']._serialized_options = b'\222?\003p\200\001'
  _globals['_SPOTIFYCONFIG'].fields_by_name['access_token']._loaded_options = None
  _globals['_SPOTIFYCONFIG'].fields_by_name['access_token']._serialized_options = b'\222?\003p\200\004'
  _globals['_SPOTIFYCONFIG'].fields_by_name['token_type']._loaded_options = None
  _globals['_SPOTIFYCONFIG'].fields_by_name['token_type']._serialized_options = b'\222?\002p@'
  _globals['_SPOTIFYCONFIG'].fields_by_name['scope']._loaded_options = None
  _globals['_SPOTIFYCONFIG'].fields_by_name['scope']._serialized_options = b'\222?\003p\200\001'
  _globals['_SPOTIFYCONFIG'].fields_by_name['refresh_token']._loaded_options = None
  _globals['_SPOTIFYCONFIG'].fields_by_name['refresh_token']._serialized_options = b'\222?\003p\200\004'
  _globals['_SPOTIFYCONFIG'].fields_by_name['device_id']._loaded_options = None
  _globals['_SPOTIFYCONFIG'].fields_by_name['device_id']._serialized_options = b'\222?\002p@'
  _globals['_LOGLEVEL']._serialized_start=2104
  _globals['_LOGLEVEL']._serialized_end=2172
  _globals['_SMARTKNOBCOMMAND']._serialized_start=2174
  _globals['_SMARTKNOBCOMMAND']._serialized_end=2254
  _globals['_FROMSMARTKNOB']._serialized_start=54
  _globals['_FROMSMARTKNOB']._serialized_end=336
  _globals['_TOSMARTKNOB']._serialized_start=339
  _globals['_TOSMARTKNOB']._serialized_end=647
  _globals['_KNOB']._serialized_start=650
  _globals['_KNOB']._serialized_end=805
  _globals['_MOTORCALIBSTATE']._serialized_start=807
  _globals['_MOTORCALIBSTATE']._serialized_end=844
  _globals['_STRAINCALIBSTATE']._serialized_start=846
  _globals['_STRAINCALIBSTATE']._serialized_end=900
  _globals['_ACK']._serialized_start=902
  _globals['_ACK']._serialized_end=922
  _globals['_LOG']._serialized_start=924
  _globals['_LOG']._serialized_end=1022
  _globals['_SMARTKNOBSTATE']._serialized_start=1025
  _globals['_SMARTKNOBSTATE']._serialized_end=1159
  _globals['_SMARTKNOBCONFIG']._serialized_start=1162
  _globals['_SMARTKNOBCONFIG']._serialized_end=1513
  _globals['_REQUESTSTATE']._serialized_start=1515
  _globals['_REQUESTSTATE']._serialized_end=1529
  _globals['_PERSISTENTCONFIGURATION']._serialized_start=1531
  _globals['_PERSISTENTCONFIGURATION']._serialized_end=1632
  _globals['_MOTORCALIBRATION']._serialized_start=1634
  _globals['_MOTORCALIBRATION']._serialized_end=1746
  _globals['_STRAINSTATE']._serialized_start=1748
  _globals['_STRAINSTATE']._serialized_end=1804
  _globals['_STRAINCALIBRATION']._serialized_start=1806
  _globals['_STRAINCALIBRATION']._serialized_end=1853
  _globals['_SPOTIFYCONFIG']._serialized_start=1856
  _globals['_SPOTIFYCONFIG']._serialized_end=2102
# @@protoc_insertion_point(module_scope)
