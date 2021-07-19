## 1. 配置交叉编译环境

## 2. **移植OpenSSL**

​	参照“**04.AM437x移植paho.mqtt.c**”

```
/opt/am4372/lib/openssl-1.1.1k/_install
```

## 3. mosquitto


### 下载

https://mosquitto.org/download/

https://mosquitto.org/files/source/mosquitto-2.0.11.tar.gz

### 解压

```shell
root@ubuntu:/home/zhou/Desktop/MQTT# tar zxvf mosquitto-2.0.11.tar.gz 
mosquitto-2.0.11/
mosquitto-2.0.11/pskfile.example
mosquitto-2.0.11/security/
mosquitto-2.0.11/security/mosquitto.apparmor
mosquitto-2.0.11/service/
mosquitto-2.0.11/service/upstart/
mosquitto-2.0.11/service/upstart/mosquitto.conf
mosquitto-2.0.11/service/svscan/
mosquitto-2.0.11/service/svscan/run
mosquitto-2.0.11/service/systemd/
mosquitto-2.0.11/service/systemd/mosquitto.service.simple
mosquitto-2.0.11/service/systemd/README
mosquitto-2.0.11/service/systemd/mosquitto.service.notify
mosquitto-2.0.11/service/monit/
mosquitto-2.0.11/service/monit/mosquitto.monit
mosquitto-2.0.11/config.mk
mosquitto-2.0.11/CMakeLists.txt
mosquitto-2.0.11/about.html
mosquitto-2.0.11/aclfile.example
mosquitto-2.0.11/ChangeLog.txt
mosquitto-2.0.11/snap/
mosquitto-2.0.11/snap/local/
mosquitto-2.0.11/snap/local/default_config.conf
mosquitto-2.0.11/snap/local/launcher.sh
mosquitto-2.0.11/snap/snapcraft.yaml
mosquitto-2.0.11/examples/
mosquitto-2.0.11/examples/mysql_log/
mosquitto-2.0.11/examples/mysql_log/mysql_log.c
mosquitto-2.0.11/examples/mysql_log/Makefile
mosquitto-2.0.11/examples/publish/
mosquitto-2.0.11/examples/publish/basic-1.c
mosquitto-2.0.11/examples/subscribe_simple/
mosquitto-2.0.11/examples/subscribe_simple/single.c
mosquitto-2.0.11/examples/subscribe_simple/callback.c
mosquitto-2.0.11/examples/subscribe_simple/multiple.c
mosquitto-2.0.11/examples/subscribe_simple/Makefile
mosquitto-2.0.11/examples/temperature_conversion/
mosquitto-2.0.11/examples/temperature_conversion/main.cpp
mosquitto-2.0.11/examples/temperature_conversion/temperature_conversion.cpp
mosquitto-2.0.11/examples/temperature_conversion/temperature_conversion.h
mosquitto-2.0.11/examples/temperature_conversion/readme.txt
mosquitto-2.0.11/examples/temperature_conversion/Makefile
mosquitto-2.0.11/examples/subscribe/
mosquitto-2.0.11/examples/subscribe/basic-1.c
mosquitto-2.0.11/mosquitto.conf
mosquitto-2.0.11/man/
mosquitto-2.0.11/man/mosquitto_ctrl_dynsec.1.meta
mosquitto-2.0.11/man/mosquitto.8
mosquitto-2.0.11/man/mosquitto_ctrl_dynsec.1
mosquitto-2.0.11/man/mosquitto_sub.1.meta
mosquitto-2.0.11/man/mqtt.7.xml
mosquitto-2.0.11/man/mosquitto-tls.7
mosquitto-2.0.11/man/mosquitto_pub.1.xml
mosquitto-2.0.11/man/CMakeLists.txt
mosquitto-2.0.11/man/mosquitto.conf.5.xml
mosquitto-2.0.11/man/mosquitto_sub.1.xml
mosquitto-2.0.11/man/html.xsl
mosquitto-2.0.11/man/libmosquitto.3.meta
mosquitto-2.0.11/man/mosquitto_passwd.1.xml
mosquitto-2.0.11/man/mqtt.7
mosquitto-2.0.11/man/mosquitto.conf.5.meta
mosquitto-2.0.11/man/mosquitto.8.xml
mosquitto-2.0.11/man/mosquitto_rr.1.meta
mosquitto-2.0.11/man/mosquitto_ctrl.1
mosquitto-2.0.11/man/mosquitto_sub.1
mosquitto-2.0.11/man/mosquitto_rr.1.xml
mosquitto-2.0.11/man/mosquitto_pub.1.meta
mosquitto-2.0.11/man/mosquitto_rr.1
mosquitto-2.0.11/man/mosquitto_ctrl.1.meta
mosquitto-2.0.11/man/mqtt.7.meta
mosquitto-2.0.11/man/mosquitto_ctrl_dynsec.1.xml
mosquitto-2.0.11/man/mosquitto.conf.5
mosquitto-2.0.11/man/libmosquitto.3
mosquitto-2.0.11/man/manpage.xsl
mosquitto-2.0.11/man/mosquitto-tls.7.xml
mosquitto-2.0.11/man/mosquitto-tls.7.meta
mosquitto-2.0.11/man/mosquitto_pub.1
mosquitto-2.0.11/man/libmosquitto.3.xml
mosquitto-2.0.11/man/mosquitto_ctrl.1.xml
mosquitto-2.0.11/man/mosquitto_passwd.1
mosquitto-2.0.11/man/mosquitto_passwd.1.meta
mosquitto-2.0.11/man/Makefile
mosquitto-2.0.11/man/mosquitto.8.meta
mosquitto-2.0.11/LICENSE.txt
mosquitto-2.0.11/installer/
mosquitto-2.0.11/installer/mosquitto.nsi
mosquitto-2.0.11/installer/mosquitto64.nsi
mosquitto-2.0.11/src/
mosquitto-2.0.11/src/control.c
mosquitto-2.0.11/src/mosquitto_broker_internal.h
mosquitto-2.0.11/src/security_default.c
mosquitto-2.0.11/src/handle_subscribe.c
mosquitto-2.0.11/src/handle_connack.c
mosquitto-2.0.11/src/mux_poll.c
mosquitto-2.0.11/src/plugin_defer.c
mosquitto-2.0.11/src/handle_disconnect.c
mosquitto-2.0.11/src/session_expiry.c
mosquitto-2.0.11/src/context.c
mosquitto-2.0.11/src/CMakeLists.txt
mosquitto-2.0.11/src/handle_connect.c
mosquitto-2.0.11/src/security.c
mosquitto-2.0.11/src/database.c
mosquitto-2.0.11/src/send_auth.c
mosquitto-2.0.11/src/persist_write.c
mosquitto-2.0.11/src/lib_load.h
mosquitto-2.0.11/src/persist_read_v234.c
mosquitto-2.0.11/src/plugin_debug.c
mosquitto-2.0.11/src/send_connack.c
mosquitto-2.0.11/src/conf.c
mosquitto-2.0.11/src/send_unsuback.c
mosquitto-2.0.11/src/plugin_public.c
mosquitto-2.0.11/src/websockets.c
mosquitto-2.0.11/src/property_broker.c
mosquitto-2.0.11/src/plugin.c
mosquitto-2.0.11/src/persist_read_v5.c
mosquitto-2.0.11/src/mux.h
mosquitto-2.0.11/src/persist_write_v5.c
mosquitto-2.0.11/src/sys_tree.h
mosquitto-2.0.11/src/memory_public.c
mosquitto-2.0.11/src/handle_auth.c
mosquitto-2.0.11/src/handle_unsubscribe.c
mosquitto-2.0.11/src/topic_tok.c
mosquitto-2.0.11/src/mux.c
mosquitto-2.0.11/src/will_delay.c
mosquitto-2.0.11/src/conf_includedir.c
mosquitto-2.0.11/src/signals.c
mosquitto-2.0.11/src/retain.c
mosquitto-2.0.11/src/subs.c
mosquitto-2.0.11/src/persist_read.c
mosquitto-2.0.11/src/bridge.c
mosquitto-2.0.11/src/xtreport.c
mosquitto-2.0.11/src/send_suback.c
mosquitto-2.0.11/src/bridge_topic.c
mosquitto-2.0.11/src/linker.syms
mosquitto-2.0.11/src/read_handle.c
mosquitto-2.0.11/src/password_mosq.c
mosquitto-2.0.11/src/service.c
mosquitto-2.0.11/src/loop.c
mosquitto-2.0.11/src/mosquitto.c
mosquitto-2.0.11/src/sys_tree.c
mosquitto-2.0.11/src/keepalive.c
mosquitto-2.0.11/src/logging.c
mosquitto-2.0.11/src/handle_publish.c
mosquitto-2.0.11/src/persist.h
mosquitto-2.0.11/src/net.c
mosquitto-2.0.11/src/mux_epoll.c
mosquitto-2.0.11/src/linker-macosx.syms
mosquitto-2.0.11/src/password_mosq.h
mosquitto-2.0.11/src/Makefile
mosquitto-2.0.11/plugins/
mosquitto-2.0.11/plugins/CMakeLists.txt
mosquitto-2.0.11/plugins/message-timestamp/
mosquitto-2.0.11/plugins/message-timestamp/CMakeLists.txt
mosquitto-2.0.11/plugins/message-timestamp/mosquitto_message_timestamp.c
mosquitto-2.0.11/plugins/message-timestamp/Makefile
mosquitto-2.0.11/plugins/README.md
mosquitto-2.0.11/plugins/auth-by-ip/
mosquitto-2.0.11/plugins/auth-by-ip/CMakeLists.txt
mosquitto-2.0.11/plugins/auth-by-ip/mosquitto_auth_by_ip.c
mosquitto-2.0.11/plugins/auth-by-ip/Makefile
mosquitto-2.0.11/plugins/payload-modification/
mosquitto-2.0.11/plugins/payload-modification/CMakeLists.txt
mosquitto-2.0.11/plugins/payload-modification/mosquitto_payload_modification.c
mosquitto-2.0.11/plugins/payload-modification/Makefile
mosquitto-2.0.11/plugins/dynamic-security/
mosquitto-2.0.11/plugins/dynamic-security/clients.c
mosquitto-2.0.11/plugins/dynamic-security/json_help.h
mosquitto-2.0.11/plugins/dynamic-security/CMakeLists.txt
mosquitto-2.0.11/plugins/dynamic-security/auth.c
mosquitto-2.0.11/plugins/dynamic-security/plugin.c
mosquitto-2.0.11/plugins/dynamic-security/clientlist.c
mosquitto-2.0.11/plugins/dynamic-security/groups.c
mosquitto-2.0.11/plugins/dynamic-security/sub_matches_sub.c
mosquitto-2.0.11/plugins/dynamic-security/dynamic_security.h
mosquitto-2.0.11/plugins/dynamic-security/json_help.c
mosquitto-2.0.11/plugins/dynamic-security/README.md
mosquitto-2.0.11/plugins/dynamic-security/roles.c
mosquitto-2.0.11/plugins/dynamic-security/acl.c
mosquitto-2.0.11/plugins/dynamic-security/grouplist.c
mosquitto-2.0.11/plugins/dynamic-security/rolelist.c
mosquitto-2.0.11/plugins/dynamic-security/Makefile
mosquitto-2.0.11/plugins/Makefile
mosquitto-2.0.11/lib/
mosquitto-2.0.11/lib/socks_mosq.h
mosquitto-2.0.11/lib/actions.c
mosquitto-2.0.11/lib/handle_connack.c
mosquitto-2.0.11/lib/linker.version
mosquitto-2.0.11/lib/handle_disconnect.c
mosquitto-2.0.11/lib/CMakeLists.txt
mosquitto-2.0.11/lib/handle_pubackcomp.c
mosquitto-2.0.11/lib/socks_mosq.c
mosquitto-2.0.11/lib/tls_mosq.c
mosquitto-2.0.11/lib/will_mosq.h
mosquitto-2.0.11/lib/handle_suback.c
mosquitto-2.0.11/lib/util_mosq.h
mosquitto-2.0.11/lib/misc_mosq.h
mosquitto-2.0.11/lib/misc_mosq.c
mosquitto-2.0.11/lib/will_mosq.c
mosquitto-2.0.11/lib/logging_mosq.c
mosquitto-2.0.11/lib/dummypthread.h
mosquitto-2.0.11/lib/handle_ping.c
mosquitto-2.0.11/lib/util_mosq.c
mosquitto-2.0.11/lib/send_connect.c
mosquitto-2.0.11/lib/handle_pubrel.c
mosquitto-2.0.11/lib/time_mosq.h
mosquitto-2.0.11/lib/send_mosq.c
mosquitto-2.0.11/lib/memory_mosq.c
mosquitto-2.0.11/lib/send_publish.c
mosquitto-2.0.11/lib/logging_mosq.h
mosquitto-2.0.11/lib/handle_auth.c
mosquitto-2.0.11/lib/packet_mosq.h
mosquitto-2.0.11/lib/net_mosq_ocsp.c
mosquitto-2.0.11/lib/send_subscribe.c
mosquitto-2.0.11/lib/net_mosq.c
mosquitto-2.0.11/lib/messages_mosq.h
mosquitto-2.0.11/lib/send_unsubscribe.c
mosquitto-2.0.11/lib/alias_mosq.c
mosquitto-2.0.11/lib/property_mosq.c
mosquitto-2.0.11/lib/utf8_mosq.c
mosquitto-2.0.11/lib/srv_mosq.c
mosquitto-2.0.11/lib/util_topic.c
mosquitto-2.0.11/lib/mosquitto_internal.h
mosquitto-2.0.11/lib/time_mosq.c
mosquitto-2.0.11/lib/thread_mosq.c
mosquitto-2.0.11/lib/options.c
mosquitto-2.0.11/lib/handle_pubrec.c
mosquitto-2.0.11/lib/handle_unsuback.c
mosquitto-2.0.11/lib/connect.c
mosquitto-2.0.11/lib/read_handle.h
mosquitto-2.0.11/lib/helpers.c
mosquitto-2.0.11/lib/cpp/
mosquitto-2.0.11/lib/cpp/CMakeLists.txt
mosquitto-2.0.11/lib/cpp/mosquittopp.cpp
mosquitto-2.0.11/lib/cpp/mosquittopp.h
mosquitto-2.0.11/lib/cpp/Makefile
mosquitto-2.0.11/lib/net_mosq.h
mosquitto-2.0.11/lib/tls_mosq.h
mosquitto-2.0.11/lib/property_mosq.h
mosquitto-2.0.11/lib/read_handle.c
mosquitto-2.0.11/lib/callbacks.c
mosquitto-2.0.11/lib/send_disconnect.c
mosquitto-2.0.11/lib/strings_mosq.c
mosquitto-2.0.11/lib/loop.c
mosquitto-2.0.11/lib/alias_mosq.h
mosquitto-2.0.11/lib/mosquitto.c
mosquitto-2.0.11/lib/packet_mosq.c
mosquitto-2.0.11/lib/send_mosq.h
mosquitto-2.0.11/lib/handle_publish.c
mosquitto-2.0.11/lib/packet_datatypes.c
mosquitto-2.0.11/lib/memory_mosq.h
mosquitto-2.0.11/lib/messages_mosq.c
mosquitto-2.0.11/lib/Makefile
mosquitto-2.0.11/cmake/
mosquitto-2.0.11/cmake/FindcJSON.cmake
mosquitto-2.0.11/README-windows.txt
mosquitto-2.0.11/client/
mosquitto-2.0.11/client/sub_test_fixed_width
mosquitto-2.0.11/client/sub_client.c
mosquitto-2.0.11/client/CMakeLists.txt
mosquitto-2.0.11/client/client_shared.c
mosquitto-2.0.11/client/client_shared.h
mosquitto-2.0.11/client/sub_test_properties
mosquitto-2.0.11/client/args.txt
mosquitto-2.0.11/client/client_props.c
mosquitto-2.0.11/client/rr_client.c
mosquitto-2.0.11/client/pub_client.c
mosquitto-2.0.11/client/sub_client_output.c
mosquitto-2.0.11/client/pub_shared.c
mosquitto-2.0.11/client/Makefile
mosquitto-2.0.11/client/sub_client_output.h
mosquitto-2.0.11/client/pub_shared.h
mosquitto-2.0.11/client/pub_test_properties
mosquitto-2.0.11/libmosquitto.pc.in
mosquitto-2.0.11/README.md
mosquitto-2.0.11/deps/
mosquitto-2.0.11/deps/uthash.h
mosquitto-2.0.11/deps/utlist.h
mosquitto-2.0.11/test/
mosquitto-2.0.11/test/mqtt5_rc.py
mosquitto-2.0.11/test/ptest.py
mosquitto-2.0.11/test/mosq_test.py
mosquitto-2.0.11/test/random/
mosquitto-2.0.11/test/random/random_client.py
mosquitto-2.0.11/test/random/auth_plugin.c
mosquitto-2.0.11/test/random/pwfile
mosquitto-2.0.11/test/random/test.py
mosquitto-2.0.11/test/random/random.conf
mosquitto-2.0.11/test/random/Makefile
mosquitto-2.0.11/test/old/
mosquitto-2.0.11/test/old/msgsps_sub.c
mosquitto-2.0.11/test/old/msgsps_common.h
mosquitto-2.0.11/test/old/msgsps_pub.c
mosquitto-2.0.11/test/old/Makefile
mosquitto-2.0.11/test/lib/
mosquitto-2.0.11/test/lib/01-keepalive-pingreq.py
mosquitto-2.0.11/test/lib/03-request-response-correlation.py
mosquitto-2.0.11/test/lib/03-publish-b2c-qos2-unexpected-pubrel.py
mosquitto-2.0.11/test/lib/01-server-keepalive-pingreq.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-len.py
mosquitto-2.0.11/test/lib/11-prop-recv-qos0.py
mosquitto-2.0.11/test/lib/08-ssl-connect-no-auth.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos1-timeout.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-receive-maximum-2.py
mosquitto-2.0.11/test/lib/03-publish-qos0-no-payload.py
mosquitto-2.0.11/test/lib/03-publish-b2c-qos2.py
mosquitto-2.0.11/test/lib/08-ssl-bad-cacert.py
mosquitto-2.0.11/test/lib/03-request-response.py
mosquitto-2.0.11/test/lib/09-util-topic-tokenise.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2.py
mosquitto-2.0.11/test/lib/11-prop-send-content-type.py
mosquitto-2.0.11/test/lib/02-subscribe-qos1.py
mosquitto-2.0.11/test/lib/02-subscribe-qos2.py
mosquitto-2.0.11/test/lib/08-ssl-connect-cert-auth-enc.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos1-len.py
mosquitto-2.0.11/test/lib/02-unsubscribe-v5.py
mosquitto-2.0.11/test/lib/01-con-discon-success.py
mosquitto-2.0.11/test/lib/08-ssl-connect-cert-auth.py
mosquitto-2.0.11/test/lib/c/
mosquitto-2.0.11/test/lib/c/02-unsubscribe-v5.c
mosquitto-2.0.11/test/lib/c/03-publish-b2c-qos1-unexpected-puback.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2-len.c
mosquitto-2.0.11/test/lib/c/03-publish-b2c-qos2.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2.c
mosquitto-2.0.11/test/lib/c/01-keepalive-pingreq.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2-pubrec-error.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos1-disconnect.c
mosquitto-2.0.11/test/lib/c/02-subscribe-qos1-async2.c
mosquitto-2.0.11/test/lib/c/02-unsubscribe.c
mosquitto-2.0.11/test/lib/c/01-unpwd-set.c
mosquitto-2.0.11/test/lib/c/03-publish-b2c-qos2-len.c
mosquitto-2.0.11/test/lib/c/01-no-clean-session.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2-maximum-qos-1.c
mosquitto-2.0.11/test/lib/c/03-publish-b2c-qos2-unexpected-pubcomp.c
mosquitto-2.0.11/test/lib/c/11-prop-recv-qos0.c
mosquitto-2.0.11/test/lib/c/01-con-discon-success.c
mosquitto-2.0.11/test/lib/c/11-prop-recv-qos1.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos1-len.c
mosquitto-2.0.11/test/lib/c/02-subscribe-qos0.c
mosquitto-2.0.11/test/lib/c/08-ssl-bad-cacert.c
mosquitto-2.0.11/test/lib/c/11-prop-send-content-type.c
mosquitto-2.0.11/test/lib/c/08-ssl-fake-cacert.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos1-receive-maximum.c
mosquitto-2.0.11/test/lib/c/08-ssl-connect-no-auth.c
mosquitto-2.0.11/test/lib/c/11-prop-oversize-packet.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2-receive-maximum-1.c
mosquitto-2.0.11/test/lib/c/03-request-response-2.c
mosquitto-2.0.11/test/lib/c/08-ssl-connect-cert-auth.c
mosquitto-2.0.11/test/lib/c/11-prop-recv-qos2.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2-receive-maximum-2.c
mosquitto-2.0.11/test/lib/c/04-retain-qos0.c
mosquitto-2.0.11/test/lib/c/02-subscribe-qos1-async1.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2-disconnect.c
mosquitto-2.0.11/test/lib/c/02-unsubscribe-multiple-v5.c
mosquitto-2.0.11/test/lib/c/03-publish-qos0-no-payload.c
mosquitto-2.0.11/test/lib/c/03-request-response-1.c
mosquitto-2.0.11/test/lib/c/01-will-unpwd-set.c
mosquitto-2.0.11/test/lib/c/01-server-keepalive-pingreq.c
mosquitto-2.0.11/test/lib/c/02-subscribe-qos1.c
mosquitto-2.0.11/test/lib/c/01-will-set.c
mosquitto-2.0.11/test/lib/c/03-publish-b2c-qos2-unexpected-pubrel.c
mosquitto-2.0.11/test/lib/c/03-publish-b2c-qos1.c
mosquitto-2.0.11/test/lib/c/03-publish-c2b-qos2-maximum-qos-0.c
mosquitto-2.0.11/test/lib/c/03-publish-qos0.c
mosquitto-2.0.11/test/lib/c/09-util-topic-tokenise.c
mosquitto-2.0.11/test/lib/c/03-request-response-correlation-1.c
mosquitto-2.0.11/test/lib/c/Makefile
mosquitto-2.0.11/test/lib/c/11-prop-send-payload-format.c
mosquitto-2.0.11/test/lib/c/02-subscribe-qos2.c
mosquitto-2.0.11/test/lib/c/08-ssl-connect-cert-auth-enc.c
mosquitto-2.0.11/test/lib/02-subscribe-qos0.py
mosquitto-2.0.11/test/lib/01-no-clean-session.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-timeout.py
mosquitto-2.0.11/test/lib/01-will-unpwd-set.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-receive-maximum-1.py
mosquitto-2.0.11/test/lib/11-prop-oversize-packet.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos1-receive-maximum.py
mosquitto-2.0.11/test/lib/01-unpwd-set.py
mosquitto-2.0.11/test/lib/02-unsubscribe-multiple-v5.py
mosquitto-2.0.11/test/lib/03-publish-b2c-qos2-unexpected-pubcomp.py
mosquitto-2.0.11/test/lib/03-publish-qos0.py
mosquitto-2.0.11/test/lib/02-unsubscribe.py
mosquitto-2.0.11/test/lib/11-prop-recv-qos1.py
mosquitto-2.0.11/test/lib/mosq_test_helper.py
mosquitto-2.0.11/test/lib/test.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos1-disconnect.py
mosquitto-2.0.11/test/lib/cpp/
mosquitto-2.0.11/test/lib/cpp/03-publish-b2c-qos2.cpp
mosquitto-2.0.11/test/lib/cpp/02-unsubscribe.cpp
mosquitto-2.0.11/test/lib/cpp/08-ssl-bad-cacert.cpp
mosquitto-2.0.11/test/lib/cpp/08-ssl-fake-cacert.cpp
mosquitto-2.0.11/test/lib/cpp/03-publish-qos0-no-payload.cpp
mosquitto-2.0.11/test/lib/cpp/03-publish-c2b-qos1-disconnect.cpp
mosquitto-2.0.11/test/lib/cpp/09-util-topic-tokenise.cpp
mosquitto-2.0.11/test/lib/cpp/08-ssl-connect-cert-auth.cpp
mosquitto-2.0.11/test/lib/cpp/08-ssl-connect-cert-auth-enc.cpp
mosquitto-2.0.11/test/lib/cpp/02-subscribe-qos2.cpp
mosquitto-2.0.11/test/lib/cpp/03-publish-c2b-qos2.cpp
mosquitto-2.0.11/test/lib/cpp/01-will-set.cpp
mosquitto-2.0.11/test/lib/cpp/03-publish-b2c-qos1.cpp
mosquitto-2.0.11/test/lib/cpp/01-con-discon-success.cpp
mosquitto-2.0.11/test/lib/cpp/08-ssl-connect-no-auth.cpp
mosquitto-2.0.11/test/lib/cpp/03-publish-c2b-qos2-disconnect.cpp
mosquitto-2.0.11/test/lib/cpp/01-will-unpwd-set.cpp
mosquitto-2.0.11/test/lib/cpp/01-keepalive-pingreq.cpp
mosquitto-2.0.11/test/lib/cpp/03-publish-qos0.cpp
mosquitto-2.0.11/test/lib/cpp/02-subscribe-qos0.cpp
mosquitto-2.0.11/test/lib/cpp/04-retain-qos0.cpp
mosquitto-2.0.11/test/lib/cpp/01-no-clean-session.cpp
mosquitto-2.0.11/test/lib/cpp/02-subscribe-qos1.cpp
mosquitto-2.0.11/test/lib/cpp/01-unpwd-set.cpp
mosquitto-2.0.11/test/lib/cpp/Makefile
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-pubrec-error.py
mosquitto-2.0.11/test/lib/11-prop-recv-qos2.py
mosquitto-2.0.11/test/lib/03-publish-b2c-qos1.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-maximum-qos-0.py
mosquitto-2.0.11/test/lib/11-prop-send-payload-format.py
mosquitto-2.0.11/test/lib/03-publish-b2c-qos1-unexpected-puback.py
mosquitto-2.0.11/test/lib/08-ssl-fake-cacert.py
mosquitto-2.0.11/test/lib/03-publish-b2c-qos2-len.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-disconnect.py
mosquitto-2.0.11/test/lib/03-publish-c2b-qos2-maximum-qos-1.py
mosquitto-2.0.11/test/lib/Makefile
mosquitto-2.0.11/test/lib/04-retain-qos0.py
mosquitto-2.0.11/test/lib/01-will-set.py
mosquitto-2.0.11/test/client/
mosquitto-2.0.11/test/client/test.sh
mosquitto-2.0.11/test/client/Makefile
mosquitto-2.0.11/test/ssl/
mosquitto-2.0.11/test/ssl/test-signing-ca.key
mosquitto-2.0.11/test/ssl/server.key
mosquitto-2.0.11/test/ssl/test-root-ca.key
mosquitto-2.0.11/test/ssl/client-revoked.key
mosquitto-2.0.11/test/ssl/test-signing-ca.crt
mosquitto-2.0.11/test/ssl/gen.sh
mosquitto-2.0.11/test/ssl/test-alt-ca.key
mosquitto-2.0.11/test/ssl/client-encrypted.crt
mosquitto-2.0.11/test/ssl/server.crt
mosquitto-2.0.11/test/ssl/test-root-ca.crt
mosquitto-2.0.11/test/ssl/server-expired.crt
mosquitto-2.0.11/test/ssl/client-expired.crt
mosquitto-2.0.11/test/ssl/signingCA/
mosquitto-2.0.11/test/ssl/signingCA/serial
mosquitto-2.0.11/test/ssl/signingCA/index.txt.attr
mosquitto-2.0.11/test/ssl/signingCA/crlnumber
mosquitto-2.0.11/test/ssl/test-bad-root-ca.crt
mosquitto-2.0.11/test/ssl/test-alt-ca.crt
mosquitto-2.0.11/test/ssl/test-bad-root-ca.key
mosquitto-2.0.11/test/ssl/client.crt
mosquitto-2.0.11/test/ssl/client-encrypted.key
mosquitto-2.0.11/test/ssl/test-fake-root-ca.key
mosquitto-2.0.11/test/ssl/client.key
mosquitto-2.0.11/test/ssl/openssl.cnf
mosquitto-2.0.11/test/ssl/server-expired.key
mosquitto-2.0.11/test/ssl/readme.txt
mosquitto-2.0.11/test/ssl/test-fake-root-ca.crt
mosquitto-2.0.11/test/ssl/rootCA/
mosquitto-2.0.11/test/ssl/rootCA/serial
mosquitto-2.0.11/test/ssl/rootCA/index.txt.attr
mosquitto-2.0.11/test/ssl/rootCA/crlnumber
mosquitto-2.0.11/test/ssl/crl-empty.pem
mosquitto-2.0.11/test/ssl/crl.pem
mosquitto-2.0.11/test/ssl/client-revoked.crt
mosquitto-2.0.11/test/ssl/all-ca.crt
mosquitto-2.0.11/test/ssl/client-expired.key
mosquitto-2.0.11/test/broker/
mosquitto-2.0.11/test/broker/12-prop-subpub-content-type.py
mosquitto-2.0.11/test/broker/12-prop-maximum-packet-size-broker.py
mosquitto-2.0.11/test/broker/08-tls-psk-pub.py
mosquitto-2.0.11/test/broker/04-retain-qos1-qos0.py
mosquitto-2.0.11/test/broker/02-subpub-qos1-bad-pubrec.py
mosquitto-2.0.11/test/broker/09-acl-change.py
mosquitto-2.0.11/test/broker/03-publish-qos1-queued-bytes.py
mosquitto-2.0.11/test/broker/02-subpub-qos1.py
mosquitto-2.0.11/test/broker/09-plugin-auth-unpwd-success.py
mosquitto-2.0.11/test/broker/12-prop-response-topic.py
mosquitto-2.0.11/test/broker/09-plugin-auth-defer-unpwd-fail.py
mosquitto-2.0.11/test/broker/09-plugin-auth-defer-unpwd-success.py
mosquitto-2.0.11/test/broker/03-publish-c2b-qos2-len.py
mosquitto-2.0.11/test/broker/01-connect-uname-password-denied.py
mosquitto-2.0.11/test/broker/02-unsubscribe-invalid-no-topic.py
mosquitto-2.0.11/test/broker/02-unsubscribe-qos1.py
mosquitto-2.0.11/test/broker/02-subpub-qos0-topic-alias-unknown.py
mosquitto-2.0.11/test/broker/04-retain-qos0-clear.py
mosquitto-2.0.11/test/broker/08-ssl-connect-no-auth.py
mosquitto-2.0.11/test/broker/02-subpub-qos0-subscription-id.py
mosquitto-2.0.11/test/broker/03-publish-qos2-max-inflight.py
mosquitto-2.0.11/test/broker/09-plugin-auth-v2-unpwd-fail.py
mosquitto-2.0.11/test/broker/02-subpub-qos0-retain-as-publish.py
mosquitto-2.0.11/test/broker/07-will-delay-session-expiry.py
mosquitto-2.0.11/test/broker/14-dynsec-client-invalid.py
mosquitto-2.0.11/test/broker/02-subpub-qos0-queued-bytes.py
mosquitto-2.0.11/test/broker/14-dynsec-modify-role.py
mosquitto-2.0.11/test/broker/02-subpub-qos2-pubrec-error.py
mosquitto-2.0.11/test/broker/08-ssl-connect-identity.py
mosquitto-2.0.11/test/broker/02-subpub-qos1-nolocal.py
mosquitto-2.0.11/test/broker/01-connect-uname-password-denied-no-will.py
mosquitto-2.0.11/test/broker/07-will-delay-reconnect.py
mosquitto-2.0.11/test/broker/dynamic-security-init.json
mosquitto-2.0.11/test/broker/02-subpub-qos2-1322.py
mosquitto-2.0.11/test/broker/06-bridge-fail-persist-resend-qos2.py
mosquitto-2.0.11/test/broker/02-subpub-qos2-bad-pubcomp.py
mosquitto-2.0.11/test/broker/01-connect-duplicate.py
mosquitto-2.0.11/test/broker/08-ssl-connect-cert-auth-revoked.py
mosquitto-2.0.11/test/broker/01-connect-uname-no-password-denied.pwfile
mosquitto-2.0.11/test/broker/10-listener-mount-point.py
mosquitto-2.0.11/test/broker/09-extended-auth-unsupported.py
mosquitto-2.0.11/test/broker/11-persistent-subscription-v5.py
mosquitto-2.0.11/test/broker/02-subpub-qos2-receive-maximum-helper.py
mosquitto-2.0.11/test/broker/12-prop-assigned-client-identifier.py
mosquitto-2.0.11/test/broker/07-will-invalid-utf8.py
mosquitto-2.0.11/test/broker/02-subpub-qos2-bad-puback-1.py
mosquitto-2.0.11/test/broker/03-pattern-matching.py
mosquitto-2.0.11/test/broker/02-subpub-qos0.py
mosquitto-2.0.11/test/broker/02-subpub-qos2.py
mosquitto-2.0.11/test/broker/14-dynsec-disable-client.py
mosquitto-2.0.11/test/broker/09-plugin-auth-context-params.py
mosquitto-2.0.11/test/broker/08-ssl-hup-disconnect.py
mosquitto-2.0.11/test/broker/14-dynsec-anon-group.py
mosquitto-2.0.11/test/broker/09-extended-auth-single.py
mosquitto-2.0.11/test/broker/02-subhier-crash.py
mosquitto-2.0.11/test/broker/02-unsubscribe-qos0.py
mosquitto-2.0.11/test/broker/07-will-delay-recover.py
mosquitto-2.0.11/test/broker/09-extended-auth-change-username.py
mosquitto-2.0.11/test/broker/12-prop-server-keepalive.py
mosquitto-2.0.11/test/broker/14-dynsec-acl.py
mosquitto-2.0.11/test/broker/09-plugin-auth-acl-pub.py
mosquitto-2.0.11/test/broker/14-dynsec-default-access.py
mosquitto-2.0.11/test/broker/08-ssl-connect-cert-auth-expired.py
mosquitto-2.0.11/test/broker/09-plugin-auth-acl-sub-denied.py
mosquitto-2.0.11/test/broker/12-prop-maximum-packet-size-publish.py
mosquitto-2.0.11/test/broker/02-subpub-qos0-long-topic.py
mosquitto-2.0.11/test/broker/14-dynsec-group-invalid.py
mosquitto-2.0.11/test/broker/02-subscribe-dollar-v5.py
mosquitto-2.0.11/test/broker/02-subscribe-qos1.py
mosquitto-2.0.11/test/broker/01-connect-zero-length-id.py
mosquitto-2.0.11/test/broker/02-subscribe-qos2.py
mosquitto-2.0.11/test/broker/03-publish-qos1-retain-disabled.py
mosquitto-2.0.11/test/broker/06-bridge-br2b-disconnect-qos1.py
mosquitto-2.0.11/test/broker/02-subscribe-persistence-flipflop.py
mosquitto-2.0.11/test/broker/06-bridge-no-local.py
mosquitto-2.0.11/test/broker/06-bridge-outgoing-retain.py
mosquitto-2.0.11/test/broker/08-ssl-connect-no-identity.py
mosquitto-2.0.11/test/broker/04-retain-check-source-persist.py
mosquitto-2.0.11/test/broker/02-subpub-qos1-message-expiry-will.py
mosquitto-2.0.11/test/broker/03-publish-qos1-max-inflight.py
mosquitto-2.0.11/test/broker/11-pub-props.py
mosquitto-2.0.11/test/broker/14-dynsec-plugin-invalid.py
mosquitto-2.0.11/test/broker/01-connect-invalid-id-0.py
mosquitto-2.0.11/test/broker/08-ssl-connect-cert-auth.py
mosquitto-2.0.11/test/broker/07-will-delay-session-expiry2.py
mosquitto-2.0.11/test/broker/01-connect-uname-or-anon.py
mosquitto-2.0.11/test/broker/c/
mosquitto-2.0.11/test/broker/c/auth_plugin_acl_sub_denied.c
mosquitto-2.0.11/test/broker/c/auth_plugin_msg_params.c
mosquitto-2.0.11/test/broker/c/auth_plugin_v5_handle_message.c
mosquitto-2.0.11/test/broker/c/auth_plugin_v2.c
mosquitto-2.0.11/test/broker/c/mosquitto_plugin_v2.h
mosquitto-2.0.11/test/broker/c/auth_plugin_extended_single2.c
mosquitto-2.0.11/test/broker/c/auth_plugin_acl.c
mosquitto-2.0.11/test/broker/c/plugin_control.c
mosquitto-2.0.11/test/broker/c/auth_plugin_v5.c
mosquitto-2.0.11/test/broker/c/auth_plugin_publish.c
mosquitto-2.0.11/test/broker/c/08-tls-psk-bridge.c
mosquitto-2.0.11/test/broker/c/auth_plugin_v4.c
mosquitto-2.0.11/test/broker/c/auth_plugin_extended_single.c
mosquitto-2.0.11/test/broker/c/08-tls-psk-pub.c
mosquitto-2.0.11/test/broker/c/auth_plugin_pwd.c
mosquitto-2.0.11/test/broker/c/auth_plugin_context_params.c
mosquitto-2.0.11/test/broker/c/auth_plugin_extended_multiple.c
mosquitto-2.0.11/test/broker/c/Makefile
mosquitto-2.0.11/test/broker/04-retain-check-source.py
mosquitto-2.0.11/test/broker/07-will-oversize-payload.py
mosquitto-2.0.11/test/broker/04-retain-upgrade-outgoing-qos.py
mosquitto-2.0.11/test/broker/02-subscribe-qos0.py
mosquitto-2.0.11/test/broker/03-publish-dollar-v5.py
mosquitto-2.0.11/test/broker/02-subpub-qos0-oversize-payload.py
mosquitto-2.0.11/test/broker/08-ssl-connect-cert-auth-crl.py
mosquitto-2.0.11/test/broker/09-plugin-auth-v2-unpwd-success.py
mosquitto-2.0.11/test/broker/03-publish-c2b-disconnect-qos2.py
mosquitto-2.0.11/test/broker/06-bridge-fail-persist-resend-qos1.py
mosquitto-2.0.11/test/broker/02-unsubscribe-qos2.py
mosquitto-2.0.11/test/broker/12-prop-maximum-packet-size-publish-qos1.py
mosquitto-2.0.11/test/broker/13-malformed-subscribe-v5.py
mosquitto-2.0.11/test/broker/06-bridge-br2b-disconnect-qos2.py
mosquitto-2.0.11/test/broker/02-subpub-qos2-bad-puback-2.py
mosquitto-2.0.11/test/broker/06-bridge-b2br-late-connection.py
mosquitto-2.0.11/test/broker/12-prop-maximum-packet-size-publish-qos2.py
mosquitto-2.0.11/test/broker/13-malformed-publish-v5.py
mosquitto-2.0.11/test/broker/01-connect-uname-password-success-no-tls.py
mosquitto-2.0.11/test/broker/06-bridge-clean-session.py
mosquitto-2.0.11/test/broker/02-subpub-qos2-receive-maximum-1.py
mosquitto-2.0.11/test/broker/01-connect-invalid-id-utf8.py
mosquitto-2.0.11/test/broker/09-acl-empty-file.py
mosquitto-2.0.11/test/broker/12-prop-response-topic-correlation-data.py
mosquitto-2.0.11/test/broker/12-prop-topic-alias-invalid.py
mosquitto-2.0.11/test/broker/09-acl-access-variants.py
mosquitto-2.0.11/test/broker/12-prop-subpub-payload-format.py
mosquitto-2.0.11/test/broker/09-auth-bad-method.py
mosquitto-2.0.11/test/broker/14-dynsec-client.py
mosquitto-2.0.11/test/broker/08-tls-psk-bridge.py
mosquitto-2.0.11/test/broker/01-connect-invalid-reserved.py
mosquitto-2.0.11/test/broker/08-tls-psk-bridge.psk
mosquitto-2.0.11/test/broker/02-subpub-qos0-send-retain.py
mosquitto-2.0.11/test/broker/02-subscribe-invalid-utf8.py
mosquitto-2.0.11/test/broker/09-plugin-publish.py
mosquitto-2.0.11/test/broker/01-connect-uname-password-success-no-tls.pwfile
mosquitto-2.0.11/test/broker/05-session-expiry-v5.py
mosquitto-2.0.11/test/broker/07-will-null-topic.py
mosquitto-2.0.11/test/broker/14-dynsec-modify-client.py
mosquitto-2.0.11/test/broker/09-extended-auth-single2.py
mosquitto-2.0.11/test/broker/09-pwfile-parse-invalid.py
mosquitto-2.0.11/test/broker/03-publish-b2c-disconnect-qos1.py
mosquitto-2.0.11/test/broker/03-publish-b2c-disconnect-qos2.py
mosquitto-2.0.11/test/broker/04-retain-qos0-repeated.py
mosquitto-2.0.11/test/broker/02-shared-qos0-v5.py
mosquitto-2.0.11/test/broker/01-connect-invalid-id-missing.py
mosquitto-2.0.11/test/broker/06-bridge-per-listener-settings.py
mosquitto-2.0.11/test/broker/14-dynsec-group.py
mosquitto-2.0.11/test/broker/01-connect-uname-invalid-utf8.py
mosquitto-2.0.11/test/broker/mosq_test_helper.py
mosquitto-2.0.11/test/broker/01-connect-uname-password-denied.pwfile
mosquitto-2.0.11/test/broker/11-persistent-subscription-no-local.py
mosquitto-2.0.11/test/broker/03-publish-b2c-qos1-len.py
mosquitto-2.0.11/test/broker/14-dynsec-auth.py
mosquitto-2.0.11/test/broker/03-publish-qos1-queued-bytes.conf
mosquitto-2.0.11/test/broker/test.py
mosquitto-2.0.11/test/broker/02-unsubscribe-qos2-multiple.py
mosquitto-2.0.11/test/broker/09-plugin-auth-unpwd-fail.py
mosquitto-2.0.11/test/broker/01-connect-uname-pwd-no-flag.py
mosquitto-2.0.11/test/broker/01-connect-success.py
mosquitto-2.0.11/test/broker/06-bridge-br2b-remapping.py
mosquitto-2.0.11/test/broker/02-subpub-qos0-topic-alias.py
mosquitto-2.0.11/test/broker/readme.txt
mosquitto-2.0.11/test/broker/04-retain-check-source-persist-diff-port.py
mosquitto-2.0.11/test/broker/07-will-properties.py
mosquitto-2.0.11/test/broker/01-connect-uname-no-flag.py
mosquitto-2.0.11/test/broker/08-tls-psk-pub.psk
mosquitto-2.0.11/test/broker/07-will-no-flag.py
mosquitto-2.0.11/test/broker/04-retain-qos0-fresh.py
mosquitto-2.0.11/test/broker/01-connect-allow-anonymous.py
mosquitto-2.0.11/test/broker/03-publish-qos2.py
mosquitto-2.0.11/test/broker/prop_subpub_helper.py
mosquitto-2.0.11/test/broker/02-subpub-qos1-message-expiry.py
mosquitto-2.0.11/test/broker/05-clean-session-qos1.py
mosquitto-2.0.11/test/broker/11-subscription-id.py
mosquitto-2.0.11/test/broker/09-extended-auth-multistep.py
mosquitto-2.0.11/test/broker/03-publish-qos1-no-subscribers-v5.py
mosquitto-2.0.11/test/broker/09-extended-auth-multistep-reauth.py
mosquitto-2.0.11/test/broker/09-plugin-auth-msg-params.py
mosquitto-2.0.11/test/broker/01-connect-disconnect-v5.py
mosquitto-2.0.11/test/broker/07-will-takeover.py
mosquitto-2.0.11/test/broker/12-prop-session-expiry-invalid.py
mosquitto-2.0.11/test/broker/01-connect-invalid-protonum.py
mosquitto-2.0.11/test/broker/02-subpub-qos2-receive-maximum-2.py
mosquitto-2.0.11/test/broker/01-connect-uname-or-anon.pwfile
mosquitto-2.0.11/test/broker/02-subpub-qos1-oversize-payload.py
mosquitto-2.0.11/test/broker/07-will-delay.py
mosquitto-2.0.11/test/broker/07-will-reconnect-1273.py
mosquitto-2.0.11/test/broker/08-ssl-bridge-helper.py
mosquitto-2.0.11/test/broker/03-publish-long-topic.py
mosquitto-2.0.11/test/broker/02-subpub-qos1-message-expiry-retain.py
mosquitto-2.0.11/test/broker/07-will-null.py
mosquitto-2.0.11/test/broker/14-dynsec-role.py
mosquitto-2.0.11/test/broker/13-malformed-unsubscribe-v5.py
mosquitto-2.0.11/test/broker/14-dynsec-role-invalid.py
mosquitto-2.0.11/test/broker/14-dynsec-modify-group.py
mosquitto-2.0.11/test/broker/01-connect-bad-packet.py
mosquitto-2.0.11/test/broker/11-persistent-subscription.py
mosquitto-2.0.11/test/broker/08-ssl-bridge.py
mosquitto-2.0.11/test/broker/06-bridge-b2br-remapping.py
mosquitto-2.0.11/test/broker/06-bridge-reconnect-local-out.py
mosquitto-2.0.11/test/broker/02-subpub-qos1-bad-pubcomp.py
mosquitto-2.0.11/test/broker/03-publish-b2c-qos2-len.py
mosquitto-2.0.11/test/broker/09-plugin-auth-acl-sub.py
mosquitto-2.0.11/test/broker/06-bridge-b2br-disconnect-qos1.py
mosquitto-2.0.11/test/broker/08-ssl-connect-cert-auth-without.py
mosquitto-2.0.11/test/broker/03-publish-dollar.py
mosquitto-2.0.11/test/broker/07-will-disconnect-with-will.py
mosquitto-2.0.11/test/broker/01-connect-uname-no-password-denied.py
mosquitto-2.0.11/test/broker/01-connect-connack-2163.py
mosquitto-2.0.11/test/broker/02-subscribe-long-topic.py
mosquitto-2.0.11/test/broker/11-message-expiry.py
mosquitto-2.0.11/test/broker/Makefile
mosquitto-2.0.11/test/broker/08-ssl-connect-no-auth-wrong-ca.py
mosquitto-2.0.11/test/broker/04-retain-qos0.py
mosquitto-2.0.11/test/broker/07-will-qos0.py
mosquitto-2.0.11/test/broker/03-publish-invalid-utf8.py
mosquitto-2.0.11/test/broker/12-prop-maximum-packet-size-connect.py
mosquitto-2.0.11/test/broker/03-publish-qos1-max-inflight-expire.py
mosquitto-2.0.11/test/broker/06-bridge-b2br-disconnect-qos2.py
mosquitto-2.0.11/test/broker/03-publish-qos1.py
mosquitto-2.0.11/test/broker/06-bridge-b2br-late-connection-retain.py
mosquitto-2.0.11/test/mqtt5_props.py
mosquitto-2.0.11/test/Makefile
mosquitto-2.0.11/test/unit/
mosquitto-2.0.11/test/unit/persist_write_stubs.c
mosquitto-2.0.11/test/unit/utf8.c
mosquitto-2.0.11/test/unit/property_add.c
mosquitto-2.0.11/test/unit/misc_trim_test.c
mosquitto-2.0.11/test/unit/bridge_topic_test.c
mosquitto-2.0.11/test/unit/stubs.c
mosquitto-2.0.11/test/unit/util_topic_test.c
mosquitto-2.0.11/test/unit/files/
mosquitto-2.0.11/test/unit/files/persist_read/
mosquitto-2.0.11/test/unit/files/persist_read/v6-sub.test-db
mosquitto-2.0.11/test/unit/files/persist_read/unsupported-version.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-client-message.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-cfg.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v5-cfg-truncated.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v4-cfg.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-cfg-truncated.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-retain.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v6-message-store.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v6-retain.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-message-store.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-bad-chunk.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v6-client-message-props.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v4-message-store.test-db
mosquitto-2.0.11/test/unit/files/persist_read/empty.test-db
mosquitto-2.0.11/test/unit/files/persist_read/corrupt-header-short.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v5-client.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-client.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v6-client-message.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v6-cfg.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v5-bad-chunk.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-sub.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v6-message-store-props.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v3-cfg-bad-dbid.test-db
mosquitto-2.0.11/test/unit/files/persist_read/v6-client.test-db
mosquitto-2.0.11/test/unit/files/persist_read/corrupt-header-long.test-db
mosquitto-2.0.11/test/unit/files/persist_write/
mosquitto-2.0.11/test/unit/files/persist_write/v6-message-store-no-ref.test-db
mosquitto-2.0.11/test/unit/files/persist_write/v4-full.test-db
mosquitto-2.0.11/test/unit/files/persist_write/empty.test-db
mosquitto-2.0.11/test/unit/test.c
mosquitto-2.0.11/test/unit/persist_write_test.c
mosquitto-2.0.11/test/unit/property_read.c
mosquitto-2.0.11/test/unit/persist_read_test.c
mosquitto-2.0.11/test/unit/publish_test.c
mosquitto-2.0.11/test/unit/subs_stubs.c
mosquitto-2.0.11/test/unit/property_write.c
mosquitto-2.0.11/test/unit/datatype_write.c
mosquitto-2.0.11/test/unit/persist_read_stubs.c
mosquitto-2.0.11/test/unit/datatype_read.c
mosquitto-2.0.11/test/unit/subs_test.c
mosquitto-2.0.11/test/unit/property_user_read.c
mosquitto-2.0.11/test/unit/Makefile
mosquitto-2.0.11/test/mqtt5_opts.py
mosquitto-2.0.11/config.h
mosquitto-2.0.11/misc/
mosquitto-2.0.11/misc/letsencrypt/
mosquitto-2.0.11/misc/letsencrypt/mosquitto-copy.sh
mosquitto-2.0.11/misc/currentcost/
mosquitto-2.0.11/misc/currentcost/cc128_read.pl
mosquitto-2.0.11/misc/currentcost/gnome-panel/
mosquitto-2.0.11/misc/currentcost/gnome-panel/CurrentCostMQTT.server
mosquitto-2.0.11/misc/currentcost/gnome-panel/CurrentCostMQTT.py
mosquitto-2.0.11/misc/currentcost/gnome-panel/currentcost.png
mosquitto-2.0.11/misc/currentcost/cc128_log_mysql.pl
mosquitto-2.0.11/misc/currentcost/cc128_parse.pl
mosquitto-2.0.11/misc/currentcost/cc128_read.py
mosquitto-2.0.11/apps/
mosquitto-2.0.11/apps/CMakeLists.txt
mosquitto-2.0.11/apps/mosquitto_passwd/
mosquitto-2.0.11/apps/mosquitto_passwd/CMakeLists.txt
mosquitto-2.0.11/apps/mosquitto_passwd/get_password.h
mosquitto-2.0.11/apps/mosquitto_passwd/get_password.c
mosquitto-2.0.11/apps/mosquitto_passwd/mosquitto_passwd.c
mosquitto-2.0.11/apps/mosquitto_passwd/Makefile
mosquitto-2.0.11/apps/db_dump/
mosquitto-2.0.11/apps/db_dump/stubs.c
mosquitto-2.0.11/apps/db_dump/db_dump.c
mosquitto-2.0.11/apps/db_dump/db_dump.h
mosquitto-2.0.11/apps/db_dump/Makefile
mosquitto-2.0.11/apps/db_dump/print.c
mosquitto-2.0.11/apps/mosquitto_ctrl/
mosquitto-2.0.11/apps/mosquitto_ctrl/dynsec_client.c
mosquitto-2.0.11/apps/mosquitto_ctrl/CMakeLists.txt
mosquitto-2.0.11/apps/mosquitto_ctrl/mosquitto_ctrl.h
mosquitto-2.0.11/apps/mosquitto_ctrl/dynsec.c
mosquitto-2.0.11/apps/mosquitto_ctrl/mosquitto_ctrl.c
mosquitto-2.0.11/apps/mosquitto_ctrl/client.c
mosquitto-2.0.11/apps/mosquitto_ctrl/options.c
mosquitto-2.0.11/apps/mosquitto_ctrl/dynsec_role.c
mosquitto-2.0.11/apps/mosquitto_ctrl/dynsec_group.c
mosquitto-2.0.11/apps/mosquitto_ctrl/example.c
mosquitto-2.0.11/apps/mosquitto_ctrl/Makefile
mosquitto-2.0.11/apps/Makefile
mosquitto-2.0.11/README-letsencrypt.md
mosquitto-2.0.11/epl-v20
mosquitto-2.0.11/include/
mosquitto-2.0.11/include/mosquitto.h
mosquitto-2.0.11/include/mosquitto_broker.h
mosquitto-2.0.11/include/mosquitto_plugin.h
mosquitto-2.0.11/include/mqtt_protocol.h
mosquitto-2.0.11/libmosquittopp.pc.in
mosquitto-2.0.11/CONTRIBUTING.md
mosquitto-2.0.11/pwfile.example
mosquitto-2.0.11/logo/
mosquitto-2.0.11/logo/mosquitto.ico
mosquitto-2.0.11/logo/legacy/
mosquitto-2.0.11/logo/legacy/mosquitto.svg
mosquitto-2.0.11/logo/legacy/mosquitto-14x14.png
mosquitto-2.0.11/logo/legacy/mosquitto-16x16.png
mosquitto-2.0.11/logo/mosquitto-logo-min.svg
mosquitto-2.0.11/logo/mosquitto-logo-only.svg
mosquitto-2.0.11/logo/mosquitto-text-below.svg
mosquitto-2.0.11/logo/mosquitto-text-side.svg
mosquitto-2.0.11/NOTICE.md
mosquitto-2.0.11/README-compiling.md
mosquitto-2.0.11/Makefile
mosquitto-2.0.11/edl-v10
```

### 编译

```shell
# 进入mosquitto-2.0.11文件夹
cd mosquitto-2.0.11
# 创建文件夹,用于make install存放生成的文件
mkdir _install    
# make
# WITH_SRV=no 不使用 SRV 查找支持构建。
# WITH_CJSON=no 编译环境原生不支持json，关闭json
# CC= gcc交叉编译器的路径
# CXX= g++交叉编译器的路径
# CFLAGS= openssl的路径
# LDFLAGS= openssl的路径
# DESTDIR=$(pwd)/_install 输出文件路径
# install 安装命令
make WITH_SRV=no WITH_CJSON=no CC=/opt/am4372/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi/bin/arm-linux-gnueabi-gcc CXX=/opt/am4372/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi/bin/arm-linux-gnueabi-g++ CFLAGS="-I/opt/openssl/openssl-1.1.1k/install/include/" LDFLAGS="-L/opt/openssl/openssl-1.1.1k/install/lib -lssl -lcrypto" DESTDIR=$(pwd)/_install install
......结果......
 
```

### 编译结果

```
# _install tree
.
├── etc
|    └── mosquitto
|        ├── aclfile.example
|        ├── mosquitto.conf.example 	# 默认配置文件
|        ├── pskfile.example
|        └── pwfile.example
... ...
└── usr
    └── local
        ├── bin
        │   ├── mosquitto_passwd
        │   ├── mosquitto_pub    #测试程序,用于向服务器端推送数据
        │   ├── mosquitto_rr
        │   └── mosquitto_sub    #测试程序,用于订阅服务端端
        ├── include    #开发需要用到的库?
... ...
        ├── lib
        │   ├── libmosquittopp.so -> libmosquittopp.so.1    #在开发板上创建软链接
        │   ├── libmosquittopp.so.1    #拷贝到开发板/usr/bin目录下
        │   ├── libmosquitto.so -> libmosquitto.so.1    #在开发板上创建软链接
        │   ├── libmosquitto.so.1    #拷贝到开发板/usr/bin目录下
        │   └── pkgconfig
        │       ├── libmosquitto.pc
        │       └── libmosquittopp.pc
        ├── sbin
        │   └── mosquitto    #MQTT服务器端
        └── share
           └── man  #这里面的是帮助手册吧!
... ...
```



[移植安装mosquitto到ubuntu和ARM开发板](https://blog.csdn.net/qq_40452910/article/details/98781922)

[ARM板研究笔记](https://www.cnblogs.com/guyk/p/12377077.html) - 1.8 mosquitto移植-MQTT

[最新MQTT客户端MOSQUITTO交叉编译全记录](https://www.hnoyi.com/2021/03/06/arm%E6%B5%B7%E6%80%9Dmqtt%E5%BC%80%E5%8F%91%E7%B3%BB%E5%88%97%EF%BC%88%E4%B8%80%EF%BC%89%E6%9C%80%E6%96%B0mqtt%E5%AE%A2%E6%88%B7%E7%AB%AFmosquitto%E4%BA%A4%E5%8F%89%E7%BC%96%E8%AF%91%E5%85%A8%E8%AE%B0/)

### 执行

```
./mosquitto -c mosquitto.conf
```

### 报错

```
4919: Warning: Unable to drop privileges to 'mosquitto' because this user does not exist. Trying 'nobody' instead.
4919: Error: Unable to drop privileges to 'nobody'.

# 修改mosquitto.conf，找到“#user mosquitto”，在后面一行增加“user root”，用户名根据实际修改
```

```
5354: Starting in local only mode. Connections will only be possible from clients running on this machine.
仅本地模式：只能本机连接，外部设备无法连接

# 修改mosquitto.conf，找到“#allow_anonymous false”，在后面一行增加“allow_anonymous true”
# 修改mosquitto.conf，找到“#listener”，在后面一行增加“listener 1883”

```





### mosquitto.conf

```

```

