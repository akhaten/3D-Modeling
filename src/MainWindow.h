//
// Created by jessy on 28/04/2021.
//

#ifndef BILLARD_MAINWINDOW_H
#define BILLARD_MAINWINDOW_H

#include <Gui/RaGui.hpp>

#include <Gui/MainWindowInterface.hpp>
#include <Gui/TreeModel/EntityTreeModel.hpp>

#include <QKeySequence>

namespace Ra::Engine::Scene {
    class Camera;
}

class MainWindow : public Ra::Gui::MainWindowInterface {

    Q_OBJECT

public:
    /** Constructors and destructor.
     *  https://en.cppreference.com/w/cpp/language/rule_of_three
     */
    /** @{ */
    explicit MainWindow( QWidget* parent = nullptr );
    MainWindow( const MainWindow& ) = delete;
    MainWindow& operator=( const MainWindow& ) = delete;
    MainWindow( MainWindow&& )                 = delete;
    MainWindow& operator=( MainWindow&& ) = delete;
    ~MainWindow() override;
    /**@}*/

    /// Access the viewer, i.e. the rendering widget.
    Ra::Gui::Viewer* getViewer() override;

    /// Access the selection manager.
    Ra::Gui::SelectionManager* getSelectionManager() override;

    /// Access the timeline.
    Ra::Gui::Timeline* getTimeline() override;

    /// Update the ui from the plugins loaded.
    void updateUi( Ra::Plugins::RadiumPluginInterface* plugin ) override;

    /// Update the UI ( most importantly gizmos ) to the modifications of the
    /// engine/
    void onFrameComplete() override;

    /// Add render in the application: UI, viewer - this method does not associate a control panel.
    void addRenderer( const std::string& name,
                      std::shared_ptr<Ra::Engine::Rendering::Renderer> e ) override;

    /// Add a control to the application. This is defined a menu entry and an interaction panel
    void addControl( const QString& tabName, const QKeySequence& shortcut );


public slots:
    /// Called when a scene is ready to display to parameterize the application window and the
    /// viewer.
    void prepareDisplay() override;
    /// Cleanup resources.
    void cleanup() override;




private:

    bool m_lockTimeSystem{false};



    /// viewer widget
    std::unique_ptr<Ra::Gui::Viewer> m_viewer;



    /// Stores and manages the current selection.
    /// Even if no selection is provided by this application, used plugins require this
    Ra::Gui::SelectionManager* m_selectionManager;

    /// Stores the internal model of engine objects for selection and visibility.
    Ra::Gui::ItemModel* m_sceneModel;

    /// Timeline gui
    Ra::Gui::Timeline* m_timeline{nullptr};

#ifdef SHOWTREEVIEW
    /// QTreeview of the scene
    QTreeView* m_sceneTreeView;
#endif
    Ra::Engine::Scene::Camera* m_initialCamera{nullptr};

    signals:
            /// Emitted when the frame loads
            void fileLoading( const QString& path );

    /// Emitted when frame must be updated
    void frameUpdate();

    /// Emitted to add plugins dir
    void addPluginsDir();

    /// Emitted to clear plugins locations
    void clearPluginsDir();

    void roChanged( Ra::Core::Utils::Index roIndex, bool visible );

    void timeFlow( bool state );

    /// Emitted when a new item is selected. An invalid entry is sent when no item is selected.
    void selectedItem( const Ra::Engine::Scene::ItemEntry& entry );

    /// Emitted when a new entity is added to the application
    void entityAdded( Ra::Engine::Scene::Entity* entity );
};







#endif //BILLARD_MAINWINDOW_H
