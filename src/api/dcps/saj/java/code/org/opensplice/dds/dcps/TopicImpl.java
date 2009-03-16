

package org.opensplice.dds.dcps;

/** 
 * Implementation of the {@link DDS.Topic} interface. 
 */ 
public class TopicImpl extends EntityImpl implements DDS.Topic { 

    /* see DDS.TopicOperations for javadoc */ 
    public int get_inconsistent_topic_status (DDS.InconsistentTopicStatusHolder status) {
        return jniGetInconsistentTopicStatus(status);
    }

    /* see DDS.TopicOperations for javadoc */ 
    public int get_qos (DDS.TopicQosHolder qos) {
        return jniGetQos(qos);
    }

    /* see DDS.TopicOperations for javadoc */ 
    public int set_qos (DDS.TopicQos qos) {
        return jniSetQos(qos);
    }

    /* see DDS.TopicOperations for javadoc */ 
    public DDS.TopicListener get_listener () {
        return jniGetListener();
    }

    /* see DDS.TopicOperations for javadoc */ 
    public int set_listener (DDS.TopicListener a_listener, int mask) {
        return jniSetListener(a_listener, mask);
    }

    /* see DDS.TopicDescriptionOperations for javadoc */ 
    public String get_type_name () {
        return jniGetTypeName();
    }

    /* see DDS.TopicDescriptionOperations for javadoc */ 
    public String get_name () {
        return jniGetName();
    }

    /* see DDS.TopicDescriptionOperations for javadoc */ 
    public DDS.DomainParticipant get_participant () {
        return jniGetParticipant();
    }

    private native int jniGetInconsistentTopicStatus(DDS.InconsistentTopicStatusHolder status);
    private native int jniGetQos(DDS.TopicQosHolder qos);
    private native int jniSetQos(DDS.TopicQos qos);
    private native DDS.TopicListener jniGetListener();
    private native int jniSetListener(DDS.TopicListener a_listener, int mask);
    private native String jniGetTypeName();
    private native String jniGetName();
    private native DDS.DomainParticipant jniGetParticipant();
}