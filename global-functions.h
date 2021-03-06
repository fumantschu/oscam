#ifndef GLOBAL_FUNCTIONS_H_
#define GLOBAL_FUNCTIONS_H_

/* ===========================
 *      protocol modules
 * =========================== */
extern int32_t monitor_send_idx(struct s_client *, char *);
extern void module_monitor(struct s_module *);
extern void module_camd35(struct s_module *);
extern void module_camd35_tcp(struct s_module *);
extern void module_camd33(struct s_module *);
extern void module_newcamd(struct s_module *);
extern void module_radegast(struct s_module *);
extern void module_oscam_ser(struct s_module *);
extern void module_cccam(struct s_module *);
extern void module_pandora(struct s_module *);
extern void module_gbox(struct s_module *);
extern void module_constcw(struct s_module *);
extern void module_csp(struct s_module *);
extern void module_dvbapi(struct s_module *);

/* ===========================
 *       card support
 * =========================== */
extern void reader_nagra(struct s_cardsystem *);
extern void reader_irdeto(struct s_cardsystem *);
extern void reader_cryptoworks(struct s_cardsystem *);
extern void reader_viaccess(struct s_cardsystem *);
extern void reader_conax(struct s_cardsystem *);
extern void reader_seca(struct s_cardsystem *);
extern void reader_videoguard1(struct s_cardsystem *);
extern void reader_videoguard2(struct s_cardsystem *);
extern void reader_videoguard12(struct s_cardsystem *);
extern void reader_dre(struct s_cardsystem *);
extern void reader_tongfang(struct s_cardsystem *);
extern void reader_bulcrypt(struct s_cardsystem *);

/* ===========================
 *         cardreaders
 * =========================== */
extern void cardreader_mouse(struct s_cardreader *crdr);
extern void cardreader_smargo(struct s_cardreader *crdr);
extern void cardreader_stapi(struct s_cardreader *crdr);
extern void pcsc_close(struct s_reader *pcsc_reader);

/* ===========================
 *           oscam
 * =========================== */
extern void cs_exit_oscam(void);
extern void cs_restart_oscam(void);
extern int32_t cs_get_restartmode(void);

int32_t restart_cardreader(struct s_reader *rdr, int32_t restart);

extern int32_t chk_global_whitelist(ECM_REQUEST *er, uint32_t *line);
extern void global_whitelist_read(void);

extern int32_t accept_connection(int32_t i, int32_t j);
extern void start_thread(void * startroutine, char * nameroutine);
extern int32_t add_job(struct s_client *cl, int8_t action, void *ptr, int32_t len);
extern void add_check(struct s_client *client, int8_t action, void *ptr, int32_t size, int32_t ms_delay);
extern int32_t reader_init(struct s_reader *);
extern int reader_reset(struct s_reader * reader);
extern void cs_reload_config(void);
extern int32_t recv_from_udpipe(uchar *);
extern char* username(struct s_client *);
extern int32_t chk_bcaid(ECM_REQUEST *, CAIDTAB *);
extern void cs_exit(int32_t sig);
extern struct s_client * create_client(IN_ADDR_T);
extern int32_t cs_auth_client(struct s_client *, struct s_auth *, const char*);
extern void cs_disconnect_client(struct s_client *);
extern struct ecm_request_t *check_cwcache(ECM_REQUEST *, struct s_client *);
extern int32_t write_to_pipe(struct s_client *, int32_t, uchar *, int32_t);
extern int32_t read_from_pipe(struct s_client *, uchar **);
extern int32_t write_ecm_answer(struct s_reader *, ECM_REQUEST *, int8_t, uint8_t, uchar *, char *);
extern uint32_t chk_provid(uchar *, uint16_t);
extern void convert_to_beta(struct s_client *cl, ECM_REQUEST *er, uint16_t caidto);
extern void get_cw(struct s_client *, ECM_REQUEST *);
extern void do_emm(struct s_client *, EMM_PACKET *);
extern ECM_REQUEST *get_ecmtask(void);
extern void send_reader_stat(struct s_reader *rdr, ECM_REQUEST *er, struct s_ecm_answer *ea, int8_t rc);
extern int32_t send_dcw(struct s_client *, ECM_REQUEST *);
extern int32_t process_input(uchar *, int32_t, int32_t);
extern int32_t has_srvid(struct s_client *cl, ECM_REQUEST *er);
extern int32_t chk_srvid(struct s_client *, ECM_REQUEST *);
extern int32_t chk_srvid_match(ECM_REQUEST *, SIDTAB *);
extern int32_t chk_srvid_match_by_caid_prov(uint16_t, uint32_t, SIDTAB *);
extern int32_t chk_sfilter(ECM_REQUEST *, PTAB*);
extern int32_t chk_ufilters(ECM_REQUEST *);
extern int32_t chk_rsfilter(struct s_reader * reader, ECM_REQUEST *);
extern int32_t chk_caid(uint16_t caid, CAIDTAB *ctab);
extern int32_t matching_reader(ECM_REQUEST *, struct s_reader *, int32_t slot); // slot=1, do also ratelimiter check, 0= no ratelimiter check
extern int32_t ecm_ratelimit_check(struct s_reader * reader, ECM_REQUEST *er, int32_t slot); // use slot=2 if called from reader so it can replace srvid
extern int32_t emm_reader_match(struct s_reader *reader, uint16_t caid, uint32_t provid);
extern void set_signal_handler(int32_t , int32_t , void (*));
extern void cs_waitforcardinit(void);
extern void cs_reinit_clients(struct s_auth *new_accounts);
extern int32_t process_client_pipe(struct s_client *cl, uchar *buf, int32_t l);
extern void update_reader_config(uchar *ptr);
extern int32_t chk_ctab(uint16_t caid, CAIDTAB *ctab);
extern int32_t chk_srvid_by_caid_prov(struct s_client *, uint16_t caid, uint32_t provid);
extern int32_t chk_srvid_by_caid_prov_rdr(struct s_reader *, uint16_t caid, uint32_t provid);
extern int32_t chk_rfilter2(uint16_t rcaid, uint32_t rprid, struct s_reader *rdr);
extern void *clientthread_init(void * init);
extern void cleanup_thread(void *var);
extern void kill_thread(struct s_client *cl);
extern void remove_reader_from_active(struct s_reader *rdr);
extern void add_reader_to_active(struct s_reader *rdr);
extern void cs_add_violation_by_ip(IN_ADDR_T ip, int32_t port, char *info);
extern void cs_add_violation(struct s_client *cl, char *info);
extern void cs_card_info(void);
extern void cs_debug_level(void);
extern void update_chid(ECM_REQUEST *ecm);
extern void free_ecm(ECM_REQUEST *ecm);

#define debug_ecm(mask, args...) \
	do { \
		if (config_WITH_DEBUG()) { \
			char buf[ECM_FMT_LEN]; \
			format_ecm(er, buf, ECM_FMT_LEN); \
			cs_debug_mask(mask, ##args); \
		} \
	} while(0)

/* ===========================
 *        oscam-config
 * =========================== */
extern int32_t  init_config(void);
extern int32_t  init_free_userdb(struct s_auth *auth);
extern void     account_set_defaults(struct s_auth *auth);
extern void     reader_set_defaults(struct s_reader *rdr);
extern struct s_auth *init_userdb(void);
extern int32_t  init_readerdb(void);
extern void free_reader(struct s_reader *rdr);
extern int32_t  init_sidtab(void);
extern void free_sidtab(struct s_sidtab *sidtab);
extern void init_free_sidtab(void);
extern int32_t init_provid(void);

extern void config_set(char *section, const char *token, char *value);
extern void config_free(void);

extern int32_t  init_srvid(void);
extern int32_t  init_tierid(void);
extern void init_len4caid(void);
extern int32_t csp_ecm_hash(ECM_REQUEST *er);
extern void chk_reader(char *token, char *value, struct s_reader *rdr);

extern void dvbapi_chk_caidtab(char *caidasc, char type);
extern void dvbapi_read_priority(void);

void check_caidtab_fn(const char *token, char *value, void *setting, FILE *f);

extern void cs_accounts_chk(void);
extern void chk_account(const char *token, char *value, struct s_auth *account);
extern void chk_sidtab(char *token, char *value, struct s_sidtab *sidtab);
extern int32_t write_services(void);
extern int32_t write_userdb(void);
extern int32_t write_config(void);
extern int32_t write_server(void);
extern void write_versionfile(void);
extern char *mk_t_caidtab(CAIDTAB *ctab);
extern char *mk_t_caidvaluetab(CAIDVALUETAB *tab);
extern char *mk_t_tuntab(TUNTAB *ttab);
extern char *mk_t_group(uint64_t grp);
extern char *mk_t_ftab(FTAB *ftab);
extern char *mk_t_camd35tcp_port(void);
extern char *mk_t_cccam_port(void);
extern char *mk_t_aeskeys(struct s_reader *rdr);
extern char *mk_t_newcamd_port(void);
extern char *mk_t_aureader(struct s_auth *account);
extern char *mk_t_nano(struct s_reader *rdr, uchar flag);
extern char *mk_t_service( uint64_t sidtabok, uint64_t sidtabno);
extern char *mk_t_logfile(void);
extern char *mk_t_iprange(struct s_ip *range);
extern char *mk_t_ecmwhitelist(struct s_ecmWhitelist *whitelist);
extern char *mk_t_ecmheaderwhitelist(struct s_ecmHeaderwhitelist *headerlist);
extern char *mk_t_cltab(CLASSTAB *clstab);
extern char *mk_t_emmbylen(struct s_reader *rdr);
extern char *mk_t_allowedprotocols(struct s_auth *account);
extern void free_mk_t(char *value);

/* ===========================
 *       oscam-garbage
 * =========================== */
#ifdef WITH_DEBUG
extern void add_garbage_debug(void *data, char *file, uint16_t line);
#define add_garbage(x)	add_garbage_debug(x,__FILE__, __LINE__)
#else
extern void add_garbage(void *data);
#endif
extern void start_garbage_collector(int32_t);
extern void stop_garbage_collector(void);

/* ===========================
 *         module-webif
 * =========================== */
extern void http_srv(void);

/* ===========================
 *         oscam-log
 * =========================== */
extern char *LOG_LIST;
extern int32_t  cs_init_log(void);
extern void cs_reinit_loghist(uint32_t size);
extern int32_t cs_open_logfiles(void);

extern void cs_log_int(uint16_t mask, int8_t lock, const uchar *buf, int32_t n, const char *fmt, ...) __attribute__ ((format (printf, 5, 6)));

#define cs_log(...)          cs_log_int(0, 1, NULL, 0, ##__VA_ARGS__)
#define cs_log_nolock(...)   cs_log_int(0, 0, NULL, 0, ##__VA_ARGS__)
#define cs_dump(buf, n, ...) cs_log_int(0, 1, buf,  n, ##__VA_ARGS__)

#define cs_debug_mask(mask, ...)         do { if (config_WITH_DEBUG()) cs_log_int(mask, 1, NULL, 0, ##__VA_ARGS__); } while(0)
#define cs_debug_mask_nolock(mask, ...)  do { if (config_WITH_DEBUG()) cs_log_int(mask, 0, NULL, 0, ##__VA_ARGS__); } while(0)
#define cs_ddump_mask(mask, buf, n, ...) do { if (config_WITH_DEBUG()) cs_log_int(mask, 1, buf , n, ##__VA_ARGS__); } while(0)

extern void log_emm_request(struct s_reader *);
extern void logCWtoFile(ECM_REQUEST *er, uchar *cw);
extern void cs_log_config(void);
extern void cs_close_log(void);
extern int32_t cs_init_statistics(void);
extern void cs_statistics(struct s_client * client);
extern void cs_disable_log(int8_t disabled);

/* ===========================
 *        oscam-reader
 * =========================== */
extern int32_t reader_cmd2icc(struct s_reader * reader, const uchar *buf, const int32_t l, uchar *response, uint16_t *response_length);
extern int32_t card_write(struct s_reader * reader, const uchar *, const uchar *, uchar *, uint16_t *);
extern int32_t check_sct_len(const unsigned char *data, int32_t off);
extern void rdr_log(struct s_reader * reader, char *,...) __attribute__ ((format (printf, 2, 3)));
extern void rdr_log_sensitive(struct s_reader * reader, char *,...) __attribute__ ((format (printf, 2, 3)));
extern void rdr_debug_mask(struct s_reader * reader, uint16_t mask, char *fmt, ...) __attribute__ ((format (printf, 3, 4)));
extern void rdr_debug_mask_sensitive(struct s_reader * reader, uint16_t mask, char *fmt, ...) __attribute__ ((format (printf, 3, 4)));
extern void rdr_ddump_mask(struct s_reader * reader, uint16_t mask, const uint8_t * buf, int n, char *fmt, ...) __attribute__ ((format (printf, 5, 6)));
extern void * start_cardreader(void *);
extern void reader_card_info(struct s_reader * reader);
extern int32_t hostResolve(struct s_reader * reader);
extern int32_t network_tcp_connection_open(struct s_reader *);
extern void network_tcp_connection_close(struct s_reader *, char *);
extern void clear_reader_pipe(struct s_reader * reader);
extern void block_connect(struct s_reader *rdr);
extern int32_t is_connect_blocked(struct s_reader *rdr);
void cs_add_entitlement(struct s_reader *rdr, uint16_t caid, uint32_t provid, uint64_t id, uint32_t class, time_t start, time_t end, uint8_t type);
extern void cs_clear_entitlement(struct s_reader *rdr);

extern void reader_do_idle(struct s_reader * reader);
extern int32_t reader_do_emm(struct s_reader * reader, EMM_PACKET *ep);
extern void reader_log_emm(struct s_reader * reader, EMM_PACKET *ep, int32_t i, int32_t rc, struct timeb *tps);
extern void reader_get_ecm(struct s_reader * reader, ECM_REQUEST *er);
extern void casc_check_dcw(struct s_reader * reader, int32_t idx, int32_t rc, uchar *cw);
extern void casc_do_sock_log(struct s_reader * reader);
extern void reader_do_card_info(struct s_reader * reader);

/* ===========================
 *        oscam-simples
 * =========================== */
extern struct s_client *cur_client(void);
extern int32_t get_threadnum(struct s_client *client);
extern char *get_tmp_dir(void);
extern int8_t check_client(struct s_client *client);
extern void aes_set_key(char *);
extern void aes_encrypt_idx(struct s_client *, uchar *, int32_t);
extern void aes_decrypt(struct s_client *, uchar *, int32_t);
extern int32_t aes_decrypt_from_list(AES_ENTRY *list, uint16_t caid, uint32_t provid,int32_t keyid, uchar *buf, int32_t n);
extern int32_t aes_present(AES_ENTRY *list, uint16_t caid, uint32_t provid,int32_t keyid);
extern void parse_aes_keys(struct s_reader *rdr,char *value);
extern char *remote_txt(void);
extern char *trim(char *);
extern int8_t strCmpSuffix(const char *str, const char *suffix);
extern char *strtolower(char *);
extern int32_t gethexval(char);
extern int32_t comp_timeb(struct timeb *tpa, struct timeb *tpb);
extern int32_t cs_atob(uchar *, char *, int32_t);
extern uint32_t cs_atoi(char *, int32_t, int32_t);
extern int32_t byte_atob(char *);
extern int32_t word_atob(char *);
extern int32_t dyn_word_atob(char *asc);
extern int32_t key_atob_l(char *, uchar *, int32_t);
extern char *key_btoa(char *, uchar *);
extern char *cs_hexdump(int32_t, const uchar *, int32_t, char *target, int32_t len);
extern in_addr_t cs_inet_order(in_addr_t);
extern char *cs_inet_ntoa(IN_ADDR_T addr);
extern void cs_inet_addr(char *txt, IN_ADDR_T *out);
extern IN_ADDR_T get_null_ip(void);
extern void set_null_ip(IN_ADDR_T *ip);
extern void set_localhost_ip(IN_ADDR_T *ip);
void cs_resolve(const char *hostname, IN_ADDR_T *ip, struct SOCKADDR *sock, socklen_t *sa_len);

#ifdef IPV6SUPPORT
#define GET_IP() *(struct in6_addr *)pthread_getspecific(getip)
#define IP_ISSET(a) !cs_in6addr_isnull(&a)
#define IP_EQUAL(a, b) cs_in6addr_equal(&a, &b)
#define IP_ASSIGN(a, b) cs_in6addr_copy(&a, &b)
#define SIN_GET_ADDR(a) ((struct sockaddr_in6 *)&a)->sin6_addr
#define SIN_GET_PORT(a) ((struct sockaddr_in6 *)&a)->sin6_port
#define SIN_GET_FAMILY(a) ((struct sockaddr_in6 *)&a)->sin6_family
extern int32_t cs_in6addr_equal(struct in6_addr *a1, struct in6_addr *a2);
extern int32_t cs_in6addr_isnull(struct in6_addr *addr);
extern int32_t cs_in6addr_lt(struct in6_addr *a, struct in6_addr *b);
extern void cs_in6addr_copy(struct in6_addr *dst, struct in6_addr *src);
extern void cs_in6addr_ipv4map(struct in6_addr *dst, in_addr_t src);
extern void cs_getIPv6fromHost(const char *hostname, struct in6_addr *addr, struct sockaddr_storage *sa, socklen_t *sa_len);
#else
#define GET_IP() *(in_addr_t *)pthread_getspecific(getip)
#define IP_ISSET(a) (a)
#define IP_EQUAL(a, b) (a == b)
#define IP_ASSIGN(a, b) (a = b)
#define SIN_GET_ADDR(a) (a.sin_addr.s_addr)
#define SIN_GET_PORT(a) (a.sin_port)
#define SIN_GET_FAMILY(a) (a.sin_family)
#endif

extern uint32_t b2i(int32_t, const uchar *);
extern uint64_t b2ll(int32_t, uchar *);
extern uchar *i2b_buf(int32_t n, uint32_t i, uchar *b);
extern uint32_t a2i(char *, int32_t);
extern int32_t boundary(int32_t, int32_t);
extern time_t cs_timegm(struct tm *tm);
extern struct tm *cs_gmtime_r(const time_t *timep, struct tm *r);
extern char *cs_ctime_r(const time_t *timep, char* buf);
extern void cs_ftime(struct timeb *);
extern int32_t cs_readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result);
extern void cs_sleepms(uint32_t);
extern void cs_sleepus(uint32_t);
extern void cs_setpriority(int32_t);
extern struct s_auth *find_user(char *);
extern int32_t check_filled(uchar *value, int32_t length);
extern void *cs_malloc(void *result, size_t size, int32_t quiterror);
extern void *cs_realloc(void *result, size_t size, int32_t quiterror);
extern char to_hex(char code);
extern void char_to_hex(const unsigned char* p_array, uint32_t p_array_len, unsigned char *result);
extern void create_rand_str(char *dst, int32_t size);
extern int32_t file_exists(const char * filename);
extern void clear_sip(struct s_ip **sip);
extern void clear_ptab(struct s_ptab *ptab);
extern void clear_ftab(struct s_ftab *ftab);
extern void clear_caidtab(struct s_caidtab *ctab);
extern void clear_tuntab(struct s_tuntab *ttab);
extern int32_t file_copy(char *srcfile, char *destfile);
extern int32_t safe_overwrite_with_bak(char *destfile, char *tmpfile, char *bakfile, int32_t forceBakOverWrite);
extern void cs_strncpy(char * destination, const char * source, size_t num);
extern char *get_servicename(struct s_client *cl, uint16_t srvid, uint16_t caid, char *buf);
extern char *get_tiername(uint16_t tierid, uint16_t caid, char *buf);
extern char *get_provider(uint16_t caid, uint32_t provid, char *buf, uint32_t buflen);
void add_provider(uint16_t caid, uint32_t provid, const char *name, const char *sat, const char *lang);
extern uchar fast_rnd(void);
extern void init_rnd(void);
extern int32_t hexserialset(struct s_reader *rdr);
extern char *monitor_get_proto(struct s_client *);
extern char *reader_get_type_desc(struct s_reader * rdr, int32_t extended);
extern int32_t cs_strnicmp(const char * str1, const char * str2, size_t num);
extern char *strnew(char *str);
extern void hexserial_to_newcamd(uchar *source, uchar *dest, uint16_t caid);
extern void newcamd_to_hexserial(uchar *source, uchar *dest, uint16_t caid);
extern int32_t check_ip(struct s_ip *ip, IN_ADDR_T n);

extern void cs_lock_create(CS_MUTEX_LOCK *l, int16_t timeout, const char *name);
extern void cs_lock_destroy(CS_MUTEX_LOCK *l);
extern void cs_rwlock_int(CS_MUTEX_LOCK *l, int8_t type);
extern void cs_rwunlock_int(CS_MUTEX_LOCK *l, int8_t type);
extern int8_t cs_try_rwlock_int(CS_MUTEX_LOCK *l, int8_t type);

#define cs_writelock(l)	cs_rwlock_int(l, WRITELOCK)
#define cs_readlock(l)	cs_rwlock_int(l, READLOCK)
#define cs_writeunlock(l)	cs_rwunlock_int(l, WRITELOCK)
#define cs_readunlock(l)	cs_rwunlock_int(l, READLOCK)
#define cs_try_writelock(l)	cs_try_rwlock_int(l, WRITELOCK)
#define cs_try_readlock(l)	cs_try_rwlock_int(l, READLOCK)

extern uint32_t cs_getIPfromHost(const char *hostname);
extern int set_socket_priority(int fd, int priority);
extern void setTCPTimeouts(int32_t socket);
extern struct s_reader *get_reader_by_label(char *lbl);
extern struct s_client *get_client_by_name(char *name);
extern struct s_auth *get_account_by_name(char *name);
extern int8_t is_valid_client(struct s_client *client);
extern int8_t check_fd_for_data(int32_t fd);

extern void add_ms_to_timespec(struct timespec *timeout, int32_t msec);
extern int32_t add_ms_to_timeb(struct timeb *tb, int32_t ms);

extern int32_t ecmfmt(uint16_t caid, uint32_t prid, uint16_t chid, uint16_t pid, uint16_t srvid, uint16_t l, uint16_t checksum, char *result, size_t size);
extern int32_t format_ecm(ECM_REQUEST *ecm, char *result, size_t size);

extern int streq(const char *s1, const char *s2);

/* ===========================
 *       module-newcamd
 * =========================== */
extern const char *newcamd_get_client_name(uint16_t client_id);

/* ===========================
 *       module-cccshare
 * =========================== */
extern void init_share(void);
extern void done_share(void);

/* ===========================
 *         module-stat
 * =========================== */
extern void init_stat(void);
extern int32_t get_best_reader(ECM_REQUEST *er);
extern void clear_reader_stat(struct s_reader *reader);
extern void add_stat(struct s_reader *rdr, ECM_REQUEST *er, int32_t ecm_time, int32_t rc);
extern void load_stat_from_file(void);
extern READER_STAT *get_stat(struct s_reader *rdr, STAT_QUERY *q);
extern void save_stat_to_file(int32_t);
extern void clear_all_stat(void);
extern uint16_t get_betatunnel_caid_to(uint16_t);
extern void housekeeping_stat(int32_t force);
extern READER_STAT **get_sorted_stat_copy(struct s_reader *rdr, int32_t reverse, int32_t *size);
extern int32_t clean_stat_by_rc(struct s_reader *rdr, int8_t rc, int8_t inverse);
extern int32_t clean_stat_by_id(struct s_reader *rdr, uint16_t caid, uint32_t prid, uint16_t srvid, uint16_t chid, uint16_t ecmlen);
extern void update_ecmlen_from_stat(struct s_reader *rdr);
extern int32_t clean_all_stats_by_rc(int8_t rc, int8_t inverse);
extern int32_t lb_valid_btun(ECM_REQUEST *er, uint16_t caidto);
extern void lb_mark_last_reader(ECM_REQUEST *er);
extern uint32_t lb_auto_timeout(ECM_REQUEST *er, uint32_t ctimeout);

/* ===========================
 *       reader-common
 * =========================== */
extern int32_t reader_device_init(struct s_reader * reader);
extern int32_t reader_checkhealth(struct s_reader * reader);
extern void reader_post_process(struct s_reader * reader);
extern int32_t reader_ecm(struct s_reader * reader, ECM_REQUEST *, struct s_ecm_answer *);
extern int32_t reader_emm(struct s_reader * reader, EMM_PACKET *);
extern struct s_cardsystem *get_cardsystem_by_caid(uint16_t caid);
extern void reader_device_close(struct s_reader * reader);
extern int8_t cs_emmlen_is_blocked(struct s_reader *rdr, int16_t len);

#ifdef WITH_COOLAPI
extern void coolapi_open_all(void);
extern void coolapi_close_all(void);
#else
static inline void coolapi_open_all(void) { };
static inline void coolapi_close_all(void) { };
#endif

#endif
