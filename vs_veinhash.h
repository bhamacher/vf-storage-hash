#ifndef VEINHASH_H
#define VEINHASH_H

#include "vein-hash_global.h"

#include <ve_storagesystem.h>
#include <QHash>

Q_DECLARE_LOGGING_CATEGORY(VEIN_STORAGE_HASH)
Q_DECLARE_LOGGING_CATEGORY(VEIN_STORAGE_HASH_VERBOSE)

namespace VeinEvent
{
  class EventData;
}

namespace VeinComponent
{
  class ComponentData;
  class EntityData;
}


namespace VeinStorage
{
  class VEINHASHSHARED_EXPORT VeinHash : public VeinEvent::StorageSystem
  {
  public:
    explicit VeinHash(QObject *t_parent=0);

    ~VeinHash();

    // stands for QHash<"entity descriptor", QHash<"component name", "component data">*>
    template <typename T>
    using ComponentStorage = QHash<T, QHash<QString, QVariant>*>;

  public:
    bool processEvent(QEvent *t_event) override;
    StorageType getStorageType() const override;
    void dumpToFile(QIODevice *t_fileDevice, bool t_overwrite) const  override;
    Q_INVOKABLE QVariant getStoredValue(int t_entityId, const QString &t_componentName) const override;
    Q_INVOKABLE bool hasStoredValue(int t_entityId, const QString &t_componentName) const override;
    bool initializeData(const QUrl &t_sourceUrl) override;

    const QHash<QString, QVariant> *getEntityDataCopy(int t_entityId) const override;
    bool hasEntity(int t_entityId) const override;

  private:
    bool processComponentData(VeinComponent::ComponentData *t_cData);
    bool processEntityEvent(VeinComponent::EntityData *t_eData);

    void sendError(const QString t_errorString, VeinEvent::EventData *t_data);

    ComponentStorage<int> *m_data = new ComponentStorage<int>();
  };
}

#endif // VEINHASH_H
