#ifdef __cplusplus
	#include "compat.h"
	
	#include <string>
    #include <set>
    #include <map>
	#include <list>
    #include <vector>
    #include <algorithm>
    #include <cmath>
    #include <cassert>
    #include <cstddef>
    #include <cstdint>
    #include <cstdlib>
	#include <functional>
	#include <string.h>
	#include <limits>
	#include <stdexcept>
	#include <memory>
	
	/*
	#include <algorithm>
	#include <any>
	#include <array>
	#include <atomic>
	#include <bit>
	#include <bitset>
	#include <cassert>
	#include <ccomplex>
	#include <cctype>
	#include <cerrno>
	#include <cfenv>
	#include <cfloat>
	#include <charconv>
	#include <chrono>
	#include <cinttypes>
	#include <ciso646>
	#include <climits>
	#include <clocale>
	#include <cmath>
	#include <codecvt>
	#include <compare>
	#include <complex>
	#include <complex.h>
	#include <concepts>
	#include <condition_variable>
	#include <csetjmp>
	#include <csignal>
	#include <cstdalign>
	#include <cstdarg>
	#include <cstdbool>
	#include <cstddef>
	#include <cstdint>
	#include <cstdio>
	#include <cstdlib>
	#include <cstring>
	#include <ctgmath>
	#include <ctime>
	#include <cuchar>
	#include <cwchar>
	#include <cwctype>
	#include <cxxabi.h>
	#include <deque>
	#include <exception>
	#include <execution>
	#include <fenv.h>
	#include <filesystem>
	#include <forward_list>
	#include <fstream>
	#include <functional>
	#include <future>
	#include <initializer_list>
	#include <iomanip>
	#include <ios>
	#include <iosfwd>
	#include <iostream>
	#include <istream>
	#include <iterator>
	#include <limits>
	#include <list>
	#include <locale>
	#include <map>
	#include <math.h>
	#include <memory>
	#include <memory_resource>
	#include <mutex>
	#include <new>
	#include <numbers>
	#include <numeric>
	#include <optional>
	#include <ostream>
	#include <queue>
	#include <random>
	#include <ranges>
	#include <ratio>
	#include <regex>
	#include <scoped_allocator>
	#include <set>
	#include <shared_mutex>
	#include <span>
	#include <sstream>
	#include <stack>
	#include <stdexcept>
	#include <stdlib.h>
	#include <stop_token>
	#include <streambuf>
	#include <string>
	#include <string_view>
	#include <system_error>
	#include <tgmath.h>
	#include <thread>
	#include <tuple>
	#include <typeindex>
	#include <typeinfo>
	#include <type_traits>
	#include <unordered_map>
	#include <unordered_set>
	#include <utility>
	#include <valarray>
	#include <variant>
	#include <vector>
	#include <version>
	*/
	
	#ifdef QT_GUI
		#include <QApplication>
		#include <QMenuBar>
		#include <QMenu>
		#include <QIcon>
		#include <QVBoxLayout>
		#include <QToolBar>
		#include <QStatusBar>
		#include <QLabel>
		#include <QMessageBox>
		#include <QMimeData>
		#include <QProgressBar>
		#include <QProgressDialog>
		#include <QStackedWidget>
		#include <QDateTime>
		#include <QMovie>
		#include <QFileDialog>
		#include <QDesktopServices>
		#include <QTimer>
		#include <QDragEnterEvent>
		#include <QUrl>
		#include <QMimeData>
		#include <QStyle>
		#include <QToolButton>
		#include <QScrollArea>
		#include <QScroller>
		#include <QTextDocument>
		#include <QInputDialog>
	#endif // QT_GUI
	
	#include "json/json_spirit_reader_template.h"
	#include "json/json_spirit_writer_template.h"
	#include "json/json_spirit_utils.h"
	#include "json/json_spirit_value.h"
	
	#include "caddrinfo.h"
	#include "blocksizecalculator.h"
	#include "checkpoints.h"
	#include "hash.h"
	#include "cregtestparams.h"
	#include "ccrypter.h"
	#include "txdb.h"
	#include "txdb-leveldb.h"
	#include "util.h"
	
	#include "serialize.h"
	#include "ckey.h"
	#include "cactivemasternode.h"
	
	#include "allocators.h"
	#include "allocators/zero_after_free_allocator.h"
	#include "allocators/secure_allocator.h"
	#include "allocators/securestring.h"
	
	#include "ctestnetparams.h"
	#include "cmainparams.h"
	#include "cblock.h"
	#include "caccountingentry.h"
	#include "cdb.h"
	#include "spork.h"
	#include "mnengine_extern.h"
	#include "calert.h"
	#include "tinyformat.h"
	#include "instantx.h"
	#include "mapvalue_t.h"
	#include "cunsignedalert.h"
	#include "velocity.h"
	#include "fork.h"
	#include "chainparams.h"
	#include "cchainparams.h"
	#include "genesis.h"
	#include "caddress.h"
	#include "mining.h"
	#include "bignum.h"
	#include "ckeyid.h"
	#include "cscriptid.h"
	#include "ctransactionlock.h"
	#include "cstealthaddress.h"
	#include "ctxindex.h"
	#include "cmasternodepayments.h"
	#include "csporkmanager.h"
	#include "cdiskblockindex.h"
	#include "cblockindex.h"
	#include "cinv.h"
	#include "coutpoint.h"
	#include "stealth.h"
	#include "cmnenginesigner.h"
	#include "cdnsseeddata.h"
	#include "cvalidationstate.h"
	#include "cmessageheader.h"
	#include "cdiskblockpos.h"
	#include "cdisktxpos.h"
	#include "comparebypriority.h"
	#include "version.h"
	#include "init.h"
	#include "coutput.h"
	#include "db.h"
	#include "masternode-payments.h"
	#include "webwalletconnector.h"
	#include "keystore.h"
	#include "ecwrapper.h"
	#include "limitedmap.h"
	#include "mapprevtx.h"
	#include "mruset.h"
	#include "csporkmessage.h"
	#include "cwalletscanstate.h"
	#include "cblocklocator.h"
	#include "cmasterkey.h"
	#include "ckeypool.h"
	#include "creservekey.h"
	#include "cscriptnum.h"
	#include "caccount.h"
	#include "cextpubkey.h"
	#include "cstealthkeymetadata.h"
	#include "cpubkey.h"
	#include "signaturechecker.h"
	#include "cscriptcompressor.h"
	#include "ckeystoreisminevisitor.h"
	#include "cscriptvisitor.h"
	#include "strlcpy.h"
	#include "chash160.h"
	#include "chash256.h"
	#include "kernel.h"
	#include "blockparams.h"
	#include "main_const.h"
	#include "scrypt.h"
	#include "chainparamsseeds.h"
	#include "ckeymetadata.h"
	#include "miner.h"
	#include "seedspec6.h"
	#include "wallet.h"
	#include "chashwriter.h"
	#include "pbkdf2.h"
	#include "hmac_sha512_ctx.h"
	#include "secp256k1_context_verify.h"
	#include "smsg_const.h"
	#include "annotatedmixin.h"
	#include "cnodestination.h"
	#include "protocol.h"
	#include "dberrors.h"
	#include "addrman.h"
	#include "chain.h"
	#include "cinpoint.h"
	#include "clientversion.h"
	#include "cnodestatestats.h"
	#include "ctxoutcompressor.h"
	#include "eccverifyhandle.h"
	#include "key.h"
	#include "masternode.h"
	#include "masternodeman.h"
	#include "message_start_size.h"
	#include "mnengine.h"
	#include "pubkey.h"
	#include "threadsafety.h"
	
	#include "net/cservice.h"
	#include "net/csubnet.h"
	#include "net/cnetaddr.h"
	#include "net/cbanentry.h"
	#include "net/banreason.h"
	#include "net/network.h"
	#include "net/have_msg_nosignal.h"
	#include "net/myclosesocket.h"
	#include "net/proxytype.h"
	
	#include "smsg/ckeyid_b.h"
	#include "smsg/stored.h"
	#include "smsg/messagedata.h"
	#include "smsg/db.h"
	#include "smsg/batchscanner.h"
	#include "smsg/address.h"
	#include "smsg/bucket.h"
	#include "smsg/crypter.h"
	#include "smsg/token.h"
	#include "smsg/securemessage.h"
	#include "smsg/options.h"
	
	#include "uint/uint160.h"
	#include "uint/uint256.h"
	#include "uint/uint512.h"
#endif // __cplusplus