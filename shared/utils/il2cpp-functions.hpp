#ifndef IL2CPP_FUNCTIONS_H
#define IL2CPP_FUNCTIONS_H

#pragma pack(push)

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include "logging.hpp"

#if !defined(UNITY_2019) && __has_include("il2cpp-runtime-stats.h")
#define UNITY_2019
#endif

#if defined(__GLIBCXX__) || defined(__GLIBCPP__)
    // We are currently compiling with GNU GCC libstdc++, so we are already using its STL implementation
    typedef std::string gnu_string;
#else

#ifndef UNITY_2019
struct _Rep {
    size_t _M_length;
    size_t _M_capacity;
    int _M_refcount;
};

struct gnu_string {
    const char* _M_p;
    // TODO: why are these needed to prevent a crash on _Type_GetName_ call? They don't contain string data!
    const char padding[9];

    const char* _M_data() const {
        return _M_p;
    }

    const _Rep* _M_rep() const {
        return &((reinterpret_cast<const _Rep *>(_M_data()))[-1]);
    }

    const char* c_str() const {
        return _M_p;
    }

    int length() const {
        return _M_rep()->_M_length;
    }
};
#endif  // UNITY_2019

#endif

struct Il2CppAssembly;
struct Il2CppObject;
struct Il2CppClass;
struct Il2CppImage;
struct Il2CppArray;
struct Il2CppType;
struct MethodInfo;
struct FieldInfo;
struct PropertyInfo;

struct EventInfo;
struct Il2CppDomain;
struct Il2CppReflectionType;
struct Il2CppException;
struct Il2CppProfiler;
struct Il2CppThread;
struct Il2CppReflectionMethod;
struct Il2CppManagedMemorySnapshot;
struct Il2CppStackFrameInfo;
struct Il2CppCustomAttrInfo;
struct Il2CppGenericClass;
struct Il2CppDefaults;

struct Il2CppTypeDefinition;
struct Il2CppGenericParameter;
struct Il2CppGenericContainer;

#include "il2cpp-api-types.h"
#include "il2cpp-metadata.h"
#include "il2cpp-class-internals.h"
// #include "il2cpp-object-internals.h"


typedef std::vector<const Il2CppAssembly*> AssemblyVector;

// A class which contains all available il2cpp functions
// Created by zoller27osu
class il2cpp_functions {
  public:
    // These methods autogenerated by Sc2ad:
    #ifdef UNITY_2019
    static int (*init)(const char* domain_name);
    static int (*init_utf16)(const Il2CppChar * domain_name);
    #else
    static void (*init)(const char* domain_name);
    static void (*init_utf16)(const Il2CppChar * domain_name);
    #endif
    static void (*shutdown)();
    static void (*set_config_dir)(const char *config_path);
    static void (*set_data_dir)(const char *data_path);
    static void (*set_temp_dir)(const char *temp_path);
    static void (*set_commandline_arguments)(int argc, const char* const argv[], const char* basedir);
    static void (*set_commandline_arguments_utf16)(int argc, const Il2CppChar * const argv[], const char* basedir);
    static void (*set_config_utf16)(const Il2CppChar * executablePath);
    static void (*set_config)(const char* executablePath);
    static void (*set_memory_callbacks)(Il2CppMemoryCallbacks * callbacks);
    static const Il2CppImage* (*get_corlib)();
    static void (*add_internal_call)(const char* name, Il2CppMethodPointer method);
    static Il2CppMethodPointer (*resolve_icall)(const char* name);
    static void* (*alloc)(size_t size);
    static void (*free)(void* ptr);
    static Il2CppClass* (*array_class_get)(Il2CppClass * element_class, uint32_t rank);
    static uint32_t (*array_length)(Il2CppArray * array);
    static uint32_t (*array_get_byte_length)(Il2CppArray * array);
    static Il2CppArray* (*array_new)(Il2CppClass * elementTypeInfo, il2cpp_array_size_t length);
    static Il2CppArray* (*array_new_specific)(Il2CppClass * arrayTypeInfo, il2cpp_array_size_t length);
    static Il2CppArray* (*array_new_full)(Il2CppClass * array_class, il2cpp_array_size_t * lengths, il2cpp_array_size_t * lower_bounds);
    static Il2CppClass* (*bounded_array_class_get)(Il2CppClass * element_class, uint32_t rank, bool bounded);
    static int (*array_element_size)(const Il2CppClass * array_class);
    static const Il2CppImage* (*assembly_get_image)(const Il2CppAssembly * assembly);
    #ifdef UNITY_2019
    static void (*class_for_each)(void(*klassReportFunc)(Il2CppClass* klass, void* userData), void* userData);
    #endif
    static const Il2CppType* (*class_enum_basetype)(Il2CppClass * klass);
    static bool (*class_is_generic)(const Il2CppClass * klass);
    static bool (*class_is_inflated)(const Il2CppClass * klass);
    static bool (*class_is_assignable_from)(Il2CppClass * klass, Il2CppClass * oklass);
    static bool (*class_is_subclass_of)(Il2CppClass * klass, Il2CppClass * klassc, bool check_interfaces);
    static bool (*class_has_parent)(Il2CppClass * klass, Il2CppClass * klassc);
    static Il2CppClass* (*class_from_il2cpp_type)(const Il2CppType * type);
    static Il2CppClass* (*class_from_name)(const Il2CppImage * image, const char* namespaze, const char *name);
    static Il2CppClass* (*class_from_system_type)(Il2CppReflectionType * type);
    static Il2CppClass* (*class_get_element_class)(Il2CppClass * klass);
    static const EventInfo* (*class_get_events)(Il2CppClass * klass, void* *iter);
    static FieldInfo* (*class_get_fields)(Il2CppClass * klass, void* *iter);
    static Il2CppClass* (*class_get_nested_types)(Il2CppClass * klass, void* *iter);
    static Il2CppClass* (*class_get_interfaces)(Il2CppClass * klass, void* *iter);
    static const PropertyInfo* (*class_get_properties)(Il2CppClass * klass, void* *iter);
    static const PropertyInfo* (*class_get_property_from_name)(Il2CppClass * klass, const char *name);
    static FieldInfo* (*class_get_field_from_name)(Il2CppClass * klass, const char *name);
    static const MethodInfo* (*class_get_methods)(Il2CppClass * klass, void* *iter);
    static const MethodInfo* (*class_get_method_from_name)(const Il2CppClass * klass, const char* name, int argsCount);
    static const char* (*class_get_name)(const Il2CppClass * klass);
    #ifdef UNITY_2019
    static void (*type_get_name_chunked)(const Il2CppType * type, void(*chunkReportFunc)(void* data, void* userData), void* userData);
    #endif
    static const char* (*class_get_namespace)(const Il2CppClass * klass);
    static Il2CppClass* (*class_get_parent)(Il2CppClass * klass);
    static Il2CppClass* (*class_get_declaring_type)(const Il2CppClass * klass);
    static int32_t (*class_instance_size)(Il2CppClass * klass);
    static size_t (*class_num_fields)(const Il2CppClass * enumKlass);
    static bool (*class_is_valuetype)(const Il2CppClass * klass);
    static int32_t (*class_value_size)(Il2CppClass * klass, uint32_t * align);
    static bool (*class_is_blittable)(const Il2CppClass * klass);
    static int (*class_get_flags)(const Il2CppClass * klass);
    static bool (*class_is_abstract)(const Il2CppClass * klass);
    static bool (*class_is_interface)(const Il2CppClass * klass);
    static int (*class_array_element_size)(const Il2CppClass * klass);
    static Il2CppClass* (*class_from_type)(const Il2CppType * type);
    static const Il2CppType* (*class_get_type)(Il2CppClass * klass);
    static uint32_t (*class_get_type_token)(Il2CppClass * klass);
    static bool (*class_has_attribute)(Il2CppClass * klass, Il2CppClass * attr_class);
    static bool (*class_has_references)(Il2CppClass * klass);
    static bool (*class_is_enum)(const Il2CppClass * klass);
    static const Il2CppImage* (*class_get_image)(Il2CppClass * klass);
    static const char* (*class_get_assemblyname)(const Il2CppClass * klass);
    static int (*class_get_rank)(const Il2CppClass * klass);
    #ifdef UNITY_2019
    static uint32_t (*class_get_data_size)(const Il2CppClass * klass);
    static void* (*class_get_static_field_data)(const Il2CppClass * klass);
    #endif
    static size_t (*class_get_bitmap_size)(const Il2CppClass * klass);
    static void (*class_get_bitmap)(Il2CppClass * klass, size_t * bitmap);
    static bool (*stats_dump_to_file)(const char *path);
    static uint64_t (*stats_get_value)(Il2CppStat stat);
    static Il2CppDomain* (*domain_get)();
    static const Il2CppAssembly* (*domain_assembly_open)(Il2CppDomain * domain, const char* name);
    static const Il2CppAssembly** (*domain_get_assemblies)(const Il2CppDomain * domain, size_t * size);
    #ifdef UNITY_2019
    static void (*raise_exception)(Il2CppException*);
    #endif
    static Il2CppException* (*exception_from_name_msg)(const Il2CppImage * image, const char *name_space, const char *name, const char *msg);
    static Il2CppException* (*get_exception_argument_null)(const char *arg);
    static void (*format_exception)(const Il2CppException * ex, char* message, int message_size);
    static void (*format_stack_trace)(const Il2CppException * ex, char* output, int output_size);
    static void (*unhandled_exception)(Il2CppException*);
    static int (*field_get_flags)(FieldInfo * field);
    static const char* (*field_get_name)(FieldInfo * field);
    static Il2CppClass* (*field_get_parent)(FieldInfo * field);
    static size_t (*field_get_offset)(FieldInfo * field);
    static const Il2CppType* (*field_get_type)(FieldInfo * field);
    static void (*field_get_value)(Il2CppObject * obj, FieldInfo * field, void *value);
    static Il2CppObject* (*field_get_value_object)(FieldInfo * field, Il2CppObject * obj);
    static bool (*field_has_attribute)(FieldInfo * field, Il2CppClass * attr_class);
    static void (*field_set_value)(Il2CppObject * obj, FieldInfo * field, void *value);
    static void (*field_static_get_value)(FieldInfo * field, void *value);
    static void (*field_static_set_value)(FieldInfo * field, void *value);
    static void (*field_set_value_object)(Il2CppObject * instance, FieldInfo * field, Il2CppObject * value);
    #ifdef UNITY_2019
    static bool (*field_is_literal)(FieldInfo * field);
    #endif
    static void (*gc_collect)(int maxGenerations);
    static int32_t (*gc_collect_a_little)();
    static void (*gc_disable)();
    static void (*gc_enable)();
    static bool (*gc_is_disabled)();
    #ifdef UNITY_2019
    static int64_t (*gc_get_max_time_slice_ns)();
    static void (*gc_set_max_time_slice_ns)(int64_t maxTimeSlice);
    static bool (*gc_is_incremental)();
    #endif
    static int64_t (*gc_get_used_size)();
    static int64_t (*gc_get_heap_size)();
    static void (*gc_wbarrier_set_field)(Il2CppObject * obj, void **targetAddress, void *object);
    #ifdef UNITY_2019
    static bool (*gc_has_strict_wbarriers)();
    static void (*gc_set_external_allocation_tracker)(void(*func)(void*, size_t, int));
    static void (*gc_set_external_wbarrier_tracker)(void(*func)(void**));
    static void (*gc_foreach_heap)(void(*func)(void* data, void* userData), void* userData);
    static void (*stop_gc_world)();
    static void (*start_gc_world)();
    #endif
    static uint32_t (*gchandle_new)(Il2CppObject * obj, bool pinned);
    static uint32_t (*gchandle_new_weakref)(Il2CppObject * obj, bool track_resurrection);
    static Il2CppObject* (*gchandle_get_target)(uint32_t gchandle);
    static void (*gchandle_free)(uint32_t gchandle);
    #ifdef UNITY_2019
    static void (*gchandle_foreach_get_target)(void(*func)(void* data, void* userData), void* userData);
    static uint32_t (*object_header_size)();
    static uint32_t (*array_object_header_size)();
    static uint32_t (*offset_of_array_length_in_array_object_header)();
    static uint32_t (*offset_of_array_bounds_in_array_object_header)();
    static uint32_t (*allocation_granularity)();
    #endif
    static void* (*unity_liveness_calculation_begin)(Il2CppClass * filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped);
    static void (*unity_liveness_calculation_end)(void* state);
    static void (*unity_liveness_calculation_from_root)(Il2CppObject * root, void* state);
    static void (*unity_liveness_calculation_from_statics)(void* state);
    static const Il2CppType* (*method_get_return_type)(const MethodInfo * method);
    static Il2CppClass* (*method_get_declaring_type)(const MethodInfo * method);
    static const char* (*method_get_name)(const MethodInfo * method);
    static const MethodInfo* (*method_get_from_reflection)(const Il2CppReflectionMethod * method);
    static Il2CppReflectionMethod* (*method_get_object)(const MethodInfo * method, Il2CppClass * refclass);
    static bool (*method_is_generic)(const MethodInfo * method);
    static bool (*method_is_inflated)(const MethodInfo * method);
    static bool (*method_is_instance)(const MethodInfo * method);
    static uint32_t (*method_get_param_count)(const MethodInfo * method);
    static const Il2CppType* (*method_get_param)(const MethodInfo * method, uint32_t index);
    static Il2CppClass* (*method_get_class)(const MethodInfo * method);
    static bool (*method_has_attribute)(const MethodInfo * method, Il2CppClass * attr_class);
    static uint32_t (*method_get_flags)(const MethodInfo * method, uint32_t * iflags);
    static uint32_t (*method_get_token)(const MethodInfo * method);
    static const char* (*method_get_param_name)(const MethodInfo * method, uint32_t index);

    // ONLY IF THE PROFILER EXISTS FOR UNITY_2019
    static void (*profiler_install)(Il2CppProfiler * prof, Il2CppProfileFunc shutdown_callback);
    static void (*profiler_set_events)(Il2CppProfileFlags events);
    static void (*profiler_install_enter_leave)(Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave);
    static void (*profiler_install_allocation)(Il2CppProfileAllocFunc callback);
    static void (*profiler_install_gc)(Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback);
    static void (*profiler_install_fileio)(Il2CppProfileFileIOFunc callback);
    static void (*profiler_install_thread)(Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end);

    static uint32_t (*property_get_flags)(const PropertyInfo * prop);
    static const MethodInfo* (*property_get_get_method)(const PropertyInfo * prop);
    static const MethodInfo* (*property_get_set_method)(const PropertyInfo * prop);
    static const char* (*property_get_name)(const PropertyInfo * prop);
    static Il2CppClass* (*property_get_parent)(const PropertyInfo * prop);
    static Il2CppClass* (*object_get_class)(Il2CppObject * obj);
    static uint32_t (*object_get_size)(Il2CppObject * obj);
    static const MethodInfo* (*object_get_virtual_method)(Il2CppObject * obj, const MethodInfo * method);
    static Il2CppObject* (*object_new)(const Il2CppClass * klass);
    // Always returns (void*)(obj + 1)
    static void* (*object_unbox)(Il2CppObject * obj);
    // If klass is not a ValueType, returns (Il2CppObject*)(*data), else boxes
    static Il2CppObject* (*value_box)(Il2CppClass * klass, void* data);
    static void (*monitor_enter)(Il2CppObject * obj);
    static bool (*monitor_try_enter)(Il2CppObject * obj, uint32_t timeout);
    static void (*monitor_exit)(Il2CppObject * obj);
    static void (*monitor_pulse)(Il2CppObject * obj);
    static void (*monitor_pulse_all)(Il2CppObject * obj);
    static void (*monitor_wait)(Il2CppObject * obj);
    static bool (*monitor_try_wait)(Il2CppObject * obj, uint32_t timeout);
    static Il2CppObject* (*runtime_invoke)(const MethodInfo * method, void *obj, void **params, Il2CppException **exc);
    static Il2CppObject* (*runtime_invoke_convert_args)(const MethodInfo * method, void *obj, Il2CppObject **params, int paramCount, Il2CppException **exc);
    static void (*runtime_class_init)(Il2CppClass * klass);
    static void (*runtime_object_init)(Il2CppObject * obj);
    static void (*runtime_object_init_exception)(Il2CppObject * obj, Il2CppException** exc);
    static void (*runtime_unhandled_exception_policy_set)(Il2CppRuntimeUnhandledExceptionPolicy value);
    static int32_t (*string_length)(Il2CppString * str);
    static Il2CppChar* (*string_chars)(Il2CppString * str);
    static Il2CppString* (*string_new)(const char* str);
    static Il2CppString* (*string_new_len)(const char* str, uint32_t length);
    static Il2CppString* (*string_new_utf16)(const Il2CppChar * text, int32_t len);
    static Il2CppString* (*string_new_wrapper)(const char* str);
    static Il2CppString* (*string_intern)(Il2CppString * str);
    static Il2CppString* (*string_is_interned)(Il2CppString * str);
    static Il2CppThread* (*thread_current)();
    static Il2CppThread* (*thread_attach)(Il2CppDomain * domain);
    static void (*thread_detach)(Il2CppThread * thread);
    static Il2CppThread** (*thread_get_all_attached_threads)(size_t * size);
    static bool (*is_vm_thread)(Il2CppThread * thread);
    static void (*current_thread_walk_frame_stack)(Il2CppFrameWalkFunc func, void* user_data);
    static void (*thread_walk_frame_stack)(Il2CppThread * thread, Il2CppFrameWalkFunc func, void* user_data);
    static bool (*current_thread_get_top_frame)(Il2CppStackFrameInfo * frame);
    static bool (*thread_get_top_frame)(Il2CppThread * thread, Il2CppStackFrameInfo * frame);
    static bool (*current_thread_get_frame_at)(int32_t offset, Il2CppStackFrameInfo * frame);
    static bool (*thread_get_frame_at)(Il2CppThread * thread, int32_t offset, Il2CppStackFrameInfo * frame);
    static int32_t (*current_thread_get_stack_depth)();
    static int32_t (*thread_get_stack_depth)(Il2CppThread * thread);
    #ifdef UNITY_2019
    static void (*override_stack_backtrace)(Il2CppBacktraceFunc stackBacktraceFunc);
    #endif
    static Il2CppObject* (*type_get_object)(const Il2CppType * type);
    static int (*type_get_type)(const Il2CppType * type);
    static Il2CppClass* (*type_get_class_or_element_class)(const Il2CppType * type);
    static char* (*type_get_name)(const Il2CppType * type);
    static bool (*type_is_byref)(const Il2CppType * type);
    static uint32_t (*type_get_attrs)(const Il2CppType * type);
    static bool (*type_equals)(const Il2CppType * type, const Il2CppType * otherType);
    static char* (*type_get_assembly_qualified_name)(const Il2CppType * type);
    #ifdef UNITY_2019
    static bool (*type_is_static)(const Il2CppType * type);
    static bool (*type_is_pointer_type)(const Il2CppType * type);
    #endif
    static const Il2CppAssembly* (*image_get_assembly)(const Il2CppImage * image);
    static const char* (*image_get_name)(const Il2CppImage * image);
    static const char* (*image_get_filename)(const Il2CppImage * image);
    static const MethodInfo* (*image_get_entry_point)(const Il2CppImage * image);
    static size_t (*image_get_class_count)(const Il2CppImage * image);
    static const Il2CppClass* (*image_get_class)(const Il2CppImage * image, size_t index);
    static Il2CppManagedMemorySnapshot* (*capture_memory_snapshot)();
    static void (*free_captured_memory_snapshot)(Il2CppManagedMemorySnapshot * snapshot);
    static void (*set_find_plugin_callback)(Il2CppSetFindPlugInCallback method);
    static void (*register_log_callback)(Il2CppLogCallback method);
    static void (*debugger_set_agent_options)(const char* options);
    static bool (*is_debugger_attached)();
    #ifdef UNITY_2019
    static void (*register_debugger_agent_transport)(Il2CppDebuggerTransport * debuggerTransport);
    static bool (*debug_get_method_info)(const MethodInfo*, Il2CppMethodDebugInfo * methodDebugInfo);
    #endif
    static void (*unity_install_unitytls_interface)(const void* unitytlsInterfaceStruct);
    static Il2CppCustomAttrInfo* (*custom_attrs_from_class)(Il2CppClass * klass);
    static Il2CppCustomAttrInfo* (*custom_attrs_from_method)(const MethodInfo * method);
    static Il2CppObject* (*custom_attrs_get_attr)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
    static bool (*custom_attrs_has_attr)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
    static Il2CppArray* (*custom_attrs_construct)(Il2CppCustomAttrInfo * cinfo);
    static void (*custom_attrs_free)(Il2CppCustomAttrInfo * ainfo);
    #ifdef UNITY_2019
    static void (*class_set_userdata)(Il2CppClass * klass, void* userdata);
    static int (*class_get_userdata_offset)();
    #endif

    // MANUALLY DEFINED CONST DEFINITIONS
    static const Il2CppType* (*class_get_type_const)(const Il2CppClass * klass);
    static const char* (*class_get_name_const)(const Il2CppClass * klass);

    // SELECT NON-API LIBIL2CPP FUNCTIONS:
    static bool (*Class_Init)(Il2CppClass* klass);

    static Il2CppClass* (*MetadataCache_GetTypeInfoFromTypeDefinitionIndex)(TypeDefinitionIndex index);
    static Il2CppClass* (*MetadataCache_GetTypeInfoFromTypeIndex)(TypeIndex index);

#ifdef UNITY_2019
    static std::string (*_Type_GetName_)(const Il2CppType *type, Il2CppTypeNameFormat format);
#else
    static gnu_string (*_Type_GetName_)(const Il2CppType *type, Il2CppTypeNameFormat format);
#endif
    // You must il2cpp_functions::free the char* when you are done with it
    static char* Type_GetName(const Il2CppType *type, Il2CppTypeNameFormat format);
    static void (*GC_free)(void* addr);

    static void (*GarbageCollector_SetWriteBarrier)(void** ptr);
    static void* (*GarbageCollector_AllocateFixed)(size_t sz, void* descr);

    static Il2CppClass* (*Class_FromIl2CppType)(Il2CppType* typ);
    static Il2CppClass* (*Class_GetPtrClass)(Il2CppClass* elementClass);
    static Il2CppClass* (*GenericClass_GetClass)(Il2CppGenericClass* gclass);
    static AssemblyVector* (*Assembly_GetAllAssemblies)();

    static const Il2CppMetadataRegistration** s_Il2CppMetadataRegistrationPtr;
    static const void** s_GlobalMetadataPtr;
    static const Il2CppGlobalMetadataHeader** s_GlobalMetadataHeaderPtr;

    static std::remove_pointer_t<decltype(il2cpp_functions::s_GlobalMetadataPtr)> s_GlobalMetadata;
    static std::remove_pointer_t<decltype(il2cpp_functions::s_GlobalMetadataHeaderPtr)> s_GlobalMetadataHeader;
    static const Il2CppDefaults* defaults;

    // must be done on-demand because the pointers aren't necessarily correct at the time of il2cpp_functions::Init
    static void CheckS_GlobalMetadata() {
        if (!s_GlobalMetadataHeader) {
            static auto& logger = getFuncLogger();
            s_GlobalMetadata = *(il2cpp_functions::s_GlobalMetadataPtr);
            s_GlobalMetadataHeader = *(il2cpp_functions::s_GlobalMetadataHeaderPtr);
            logger.debug("sanity: %X (should be 0xFAB11BAF)", s_GlobalMetadataHeader->sanity);
            logger.debug("version: %i", s_GlobalMetadataHeader->version);
            assert(s_GlobalMetadataHeader->sanity == 0xFAB11BAF);
            logger.debug("typeDefinitionsOffset: %i", s_GlobalMetadataHeader->typeDefinitionsOffset);
            logger.debug("exportedTypeDefinitionsOffset: %i", s_GlobalMetadataHeader->exportedTypeDefinitionsOffset);
            logger.debug("nestedTypesOffset: %i", s_GlobalMetadataHeader->nestedTypesOffset);
            // TODO: use il2cpp_functions::defaults to define the il2cpp_defaults variable mentioned in il2cpp-class-internals.h
        }
    }

    // COPIES OF FREQUENTLY INLINED NON-API LIBIL2CPP FUNCTIONS:
    static const char* MetadataCache_GetStringFromIndex(StringIndex index);
    static const Il2CppTypeDefinition* MetadataCache_GetTypeDefinitionFromIndex(TypeDefinitionIndex index);
    static TypeDefinitionIndex MetadataCache_GetExportedTypeFromIndex(TypeDefinitionIndex index);
    static const Il2CppGenericContainer* MetadataCache_GetGenericContainerFromIndex(GenericContainerIndex index);
    static const Il2CppGenericParameter* MetadataCache_GetGenericParameterFromIndex(GenericParameterIndex index);
    static Il2CppClass* MetadataCache_GetNestedTypeFromIndex(NestedTypeIndex index);
    static TypeDefinitionIndex MetadataCache_GetIndexForTypeDefinition(const Il2CppClass* typeDefinition);

    // Whether all of the il2cpp functions have been initialized or not
    static bool initialized;
    // Initializes all of the IL2CPP functions via dlopen and dlsym for use.
    static void Init();

    static LoggerContextObject& getFuncLogger();
};

#pragma pack(pop)

#endif /* IL2CPP_FUNCTIONS_H */