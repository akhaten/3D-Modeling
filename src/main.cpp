//
// Created by jessy on 28/04/2021.
//

#include "MainWindow.h"
#include "MainApplication.h"

#include <Core/Geometry/MeshPrimitives.hpp>
#include <Engine/Scene/EntityManager.hpp>
#include <Engine/Scene/GeometryComponent.hpp>
#include <Engine/Scene/GeometrySystem.hpp>

class MainWindowFactory : public Ra::Gui::BaseApplication::WindowFactory
{
public:
    using Ra::Gui::BaseApplication::WindowFactory::WindowFactory;
    Ra::Gui::MainWindowInterface* createMainWindow() const override {
        return new MainWindow();
    }
};






int main(int argc, char **argv){

    MainApplication app( argc, argv );
    app.initialize(MainWindowFactory());

    //! [Define color]
    auto Brown = Ra::Core::Utils::Color::fromChars(101,56,24);
    auto GreenForest = Ra::Core::Utils::Color::fromChars(0,110,51);
    auto Grey = Ra::Core::Utils::Color::Grey();
    auto col_billard_ext = Brown;
    auto col_billard_table = GreenForest;


    //! [Create a geometry component with the table]
    auto table_lenght= 3.f;
    auto table_width = 2.f;
    auto thickness = 0.01f;

    auto table = Ra::Core::Geometry::makeSharpBox({table_width, thickness, table_lenght});
    table.addAttrib("in_color", Ra::Core::Vector4Array {table.vertices().size(), col_billard_table});
    Ra::Engine::Scene::Entity* entity_table = app.m_engine->getEntityManager()->createEntity( "Table" );
    Ra::Core::Transform transform_t( Ra::Core::Transform::Identity() );
    transform_t.translation() = Ra::Core::Vector3(0.f, thickness, 0.f);
    entity_table->setTransform(transform_t);
    entity_table->swapTransformBuffers();
    auto component_table = new Ra::Engine::Scene::TriangleMeshComponent("Table Mesh", entity_table, std::move(table), nullptr);

    //! [Create a geometry components with the cylinders]

    auto cylinder_radius = 1.f/8.f*table_width;
    auto cylinder_thickness = thickness+0.02f;

    auto c1 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, cylinder_thickness, 0.f}, cylinder_radius);
    c1.addAttrib("in_color", Ra::Core::Vector4Array {Ra::Core::Utils::Color::Black()});
    Ra::Engine::Scene::Entity* entity_c1 = app.m_engine->getEntityManager()->createEntity( "Cylinder 1" );
    Ra::Core::Transform transform_c1( Ra::Core::Transform::Identity() );
    transform_c1.translation() = Ra::Core::Vector3(table_width, 0.f, table_lenght);
    entity_c1->setTransform(transform_c1);
    entity_c1->swapTransformBuffers();
    auto component_c1 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder 1 Mesh", entity_c1, std::move(c1), nullptr);

    auto c2 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, cylinder_thickness, 0.f}, cylinder_radius);
    c2.addAttrib("in_color", Ra::Core::Vector4Array {Ra::Core::Utils::Color::Black()});
    Ra::Engine::Scene::Entity* entity_c2 = app.m_engine->getEntityManager()->createEntity( "Cylinder 2" );
    Ra::Core::Transform transform_c2( Ra::Core::Transform::Identity() );
    transform_c2.translation() = Ra::Core::Vector3(table_width, 0.f, 0);
    entity_c2->setTransform(transform_c2);
    entity_c2->swapTransformBuffers();
    auto component_c2 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder 2 Mesh", entity_c2, std::move(c2), nullptr);

    auto c3 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, cylinder_thickness, 0.f}, cylinder_radius);
    c3.addAttrib("in_color", Ra::Core::Vector4Array {Ra::Core::Utils::Color::Black()});
    Ra::Engine::Scene::Entity* entity_c3 = app.m_engine->getEntityManager()->createEntity( "Cylinder 3" );
    Ra::Core::Transform transform_c3( Ra::Core::Transform::Identity() );
    transform_c3.translation() = Ra::Core::Vector3(table_width, 0.f, -table_lenght);
    entity_c3->setTransform(transform_c3);
    entity_c3->swapTransformBuffers();
    auto component_c3 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder 3 Mesh", entity_c3, std::move(c3), nullptr);

    auto c4 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, cylinder_thickness, 0.f}, cylinder_radius);
    c4.addAttrib("in_color", Ra::Core::Vector4Array {Ra::Core::Utils::Color::Black()});
    Ra::Engine::Scene::Entity* entity_c4 = app.m_engine->getEntityManager()->createEntity( "Cylinder 4" );
    Ra::Core::Transform transform_c4( Ra::Core::Transform::Identity() );
    transform_c4.translation() = Ra::Core::Vector3(-table_width, 0.f, table_lenght);
    entity_c4->setTransform(transform_c4);
    entity_c4->swapTransformBuffers();
    auto component_c4 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder 4 Mesh", entity_c4, std::move(c4), nullptr);

    auto c5 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, cylinder_thickness, 0.f}, cylinder_radius);
    c5.addAttrib("in_color", Ra::Core::Vector4Array {Ra::Core::Utils::Color::Black()});
    Ra::Engine::Scene::Entity* entity_c5 = app.m_engine->getEntityManager()->createEntity( "Cylinder 5" );
    Ra::Core::Transform transform_c5( Ra::Core::Transform::Identity() );
    transform_c5.translation() = Ra::Core::Vector3(-table_width, 0.f, 0);
    entity_c5->setTransform(transform_c5);
    entity_c5->swapTransformBuffers();
    auto component_c5 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder 5 Mesh", entity_c5, std::move(c5), nullptr);

    auto c6 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, cylinder_thickness, 0.f}, cylinder_radius);
    c6.addAttrib("in_color", Ra::Core::Vector4Array {Ra::Core::Utils::Color::Black()});
    Ra::Engine::Scene::Entity* entity_c6 = app.m_engine->getEntityManager()->createEntity( "Cylinder 6" );
    Ra::Core::Transform transform_c6( Ra::Core::Transform::Identity() );
    transform_c6.translation() = Ra::Core::Vector3(-table_width, 0.f, -table_lenght);
    entity_c6->setTransform(transform_c6);
    entity_c6->swapTransformBuffers();
    auto component_c6 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder 6 Mesh", entity_c6, std::move(c6), nullptr);


    //! [Create a geometry components with the boarders]
    auto border_cylinder_thickness = 0.025f;
    auto boarder_thickness = cylinder_radius*0.5f;
    auto border_lenght_side_lenght = table_lenght*0.5f-cylinder_radius;

    auto b1 = Ra::Core::Geometry::makeSharpBox({boarder_thickness, 0.1f, border_lenght_side_lenght});
    b1.addAttrib("in_color", Ra::Core::Vector4Array {b1.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_b1 = app.m_engine->getEntityManager()->createEntity( "Boarder 1" );
    Ra::Core::Transform transform_b1( Ra::Core::Transform::Identity() );
    transform_b1.translation() = Ra::Core::Vector3(-(table_width+boarder_thickness), 0.1f, -(table_lenght*0.5f));
    entity_b1->setTransform(transform_b1);
    entity_b1->swapTransformBuffers();
    auto component_b1 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder 1 Mesh", entity_b1, std::move(b1), nullptr);

    auto b2 = Ra::Core::Geometry::makeSharpBox({boarder_thickness, 0.1f, border_lenght_side_lenght});
    b2.addAttrib("in_color", Ra::Core::Vector4Array {b2.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_b2 = app.m_engine->getEntityManager()->createEntity( "Boarder 2" );
    Ra::Core::Transform transform_b2( Ra::Core::Transform::Identity() );
    transform_b2.translation() = Ra::Core::Vector3(-(table_width+boarder_thickness), 0.1f, (table_lenght*0.5f));
    entity_b2->setTransform(transform_b2);
    entity_b2->swapTransformBuffers();
    auto component_b2 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder 2 Mesh", entity_b2, std::move(b2), nullptr);

    auto b3 = Ra::Core::Geometry::makeSharpBox({boarder_thickness, 0.1f, border_lenght_side_lenght});
    b3.addAttrib("in_color", Ra::Core::Vector4Array {b3.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_b3 = app.m_engine->getEntityManager()->createEntity( "Boarder 3" );
    Ra::Core::Transform transform_b3( Ra::Core::Transform::Identity() );
    transform_b3.translation() = Ra::Core::Vector3((table_width+boarder_thickness), 0.1f, -(table_lenght*0.5f));
    entity_b3->setTransform(transform_b3);
    entity_b3->swapTransformBuffers();
    auto component_b3 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder 3 Mesh", entity_b3, std::move(b3), nullptr);

    auto b4 = Ra::Core::Geometry::makeSharpBox({boarder_thickness, 0.1f, border_lenght_side_lenght});
    b4.addAttrib("in_color", Ra::Core::Vector4Array {b4.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_b4 = app.m_engine->getEntityManager()->createEntity( "Boarder 4" );
    Ra::Core::Transform transform_b4( Ra::Core::Transform::Identity() );
    transform_b4.translation() = Ra::Core::Vector3((table_width+boarder_thickness), 0.1f, (table_lenght*0.5f));
    entity_b4->setTransform(transform_b4);
    entity_b4->swapTransformBuffers();
    auto component_b4 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder 4 Mesh", entity_b4, std::move(b4), nullptr);

    auto border_lenght_side_width = table_width-cylinder_radius;

    auto b5 = Ra::Core::Geometry::makeSharpBox({border_lenght_side_width, 0.1f, boarder_thickness});
    b5.addAttrib("in_color", Ra::Core::Vector4Array {b5.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_b5 = app.m_engine->getEntityManager()->createEntity( "Boarder 5" );
    Ra::Core::Transform transform_b5( Ra::Core::Transform::Identity() );
    transform_b5.translation() = Ra::Core::Vector3(0.f, 0.1f, (table_lenght+boarder_thickness));
    entity_b5->setTransform(transform_b5);
    entity_b5->swapTransformBuffers();
    auto component_b5 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder 5 Mesh", entity_b5, std::move(b5), nullptr);

    auto b6 = Ra::Core::Geometry::makeSharpBox({border_lenght_side_width, 0.1f, boarder_thickness});
    b6.addAttrib("in_color", Ra::Core::Vector4Array {b6.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_b6 = app.m_engine->getEntityManager()->createEntity( "Boarder 6" );
    Ra::Core::Transform transform_b6( Ra::Core::Transform::Identity() );
    transform_b6.translation() = Ra::Core::Vector3(0.f, 0.1f, -(table_lenght+boarder_thickness));
    entity_b6->setTransform(transform_b6);
    entity_b6->swapTransformBuffers();
    auto component_b6 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder 6 Mesh", entity_b6, std::move(b6), nullptr);

    //! [Create a geometry component with the subtable]

    auto subtable_lenght = table_lenght+2.f*boarder_thickness+border_cylinder_thickness;
    auto subtable_width = table_width+2.f*boarder_thickness+border_cylinder_thickness;
    auto subtable_thickness = thickness-0.005f;
    auto subtable = Ra::Core::Geometry::makeSharpBox({subtable_width, subtable_thickness, subtable_lenght});
    subtable.addAttrib("in_color", Ra::Core::Vector4Array {subtable.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_subtable = app.m_engine->getEntityManager()->createEntity( "Subtable" );
    Ra::Core::Transform transform_subtable( Ra::Core::Transform::Identity() );
    transform_subtable.translation() = Ra::Core::Vector3(0.f, -subtable_thickness, 0.f);
    entity_subtable->setTransform(transform_subtable);
    entity_subtable->swapTransformBuffers();
    auto component_subtable = new Ra::Engine::Scene::TriangleMeshComponent("Subtable Mesh", entity_subtable, std::move(subtable), nullptr);


    //! [Create a geometry component with the boarder cylinder]

    auto border_cylinder_height = 0.1f;

    auto bc1 = Ra::Core::Geometry::makeSharpBox({0.5f*border_cylinder_thickness, border_cylinder_height, table_lenght+cylinder_radius+border_cylinder_thickness});
    bc1.addAttrib("in_color", Ra::Core::Vector4Array {bc1.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_bc1 = app.m_engine->getEntityManager()->createEntity( "Boarder cylinder 1" );
    Ra::Core::Transform transform_bc1( Ra::Core::Transform::Identity() );
    transform_bc1.translation() = Ra::Core::Vector3(subtable_width-0.5f*border_cylinder_thickness, border_cylinder_height, 0.f);
    entity_bc1->setTransform(transform_bc1);
    entity_bc1->swapTransformBuffers();
    auto component_bc1 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder cylinder 1 Mesh", entity_bc1, std::move(bc1), nullptr);

    auto bc2 = Ra::Core::Geometry::makeSharpBox({0.5f*border_cylinder_thickness, border_cylinder_height, table_lenght+cylinder_radius+border_cylinder_thickness});
    bc2.addAttrib("in_color", Ra::Core::Vector4Array {bc2.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_bc2 = app.m_engine->getEntityManager()->createEntity( "Boarder cylinder 2" );
    Ra::Core::Transform transform_bc2( Ra::Core::Transform::Identity() );
    transform_bc2.translation() = Ra::Core::Vector3(-(subtable_width-0.5f*border_cylinder_thickness), border_cylinder_height, 0.f);
    entity_bc2->setTransform(transform_bc2);
    entity_bc2->swapTransformBuffers();
    auto component_bc2 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder cylinder 2 Mesh", entity_bc2, std::move(bc2), nullptr);

    auto bc3 = Ra::Core::Geometry::makeSharpBox({table_width+cylinder_radius, border_cylinder_height, 0.5f*border_cylinder_thickness});
    bc3.addAttrib("in_color", Ra::Core::Vector4Array {bc3.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_bc3 = app.m_engine->getEntityManager()->createEntity( "Boarder cylinder 3" );
    Ra::Core::Transform transform_bc3( Ra::Core::Transform::Identity() );
    transform_bc3.translation() = Ra::Core::Vector3(0.f, border_cylinder_height, subtable_lenght-0.5f*border_cylinder_thickness);
    entity_bc3->setTransform(transform_bc3);
    entity_bc3->swapTransformBuffers();
    auto component_bc3 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder cylinder 3 Mesh", entity_bc3, std::move(bc3), nullptr);

    auto bc4 = Ra::Core::Geometry::makeSharpBox({table_width+cylinder_radius, border_cylinder_height, 0.5f*border_cylinder_thickness});
    bc4.addAttrib("in_color", Ra::Core::Vector4Array {bc4.vertices().size(), col_billard_ext});
    Ra::Engine::Scene::Entity* entity_bc4 = app.m_engine->getEntityManager()->createEntity( "Boarder cylinder 4" );
    Ra::Core::Transform transform_bc4( Ra::Core::Transform::Identity() );
    transform_bc4.translation() = Ra::Core::Vector3(0.f, border_cylinder_height, -(subtable_lenght-0.5f*border_cylinder_thickness));
    entity_bc4->setTransform(transform_bc4);
    entity_bc4->swapTransformBuffers();
    auto component_bc4 = new Ra::Engine::Scene::TriangleMeshComponent("Boarder cylinder 4 Mesh", entity_bc4, std::move(bc4), nullptr);

    //! [Create a geometry component with the table leg]

    auto table_leg_side = 0.5f*cylinder_radius;
    auto table_leg_weight = 1.5f;

    //! [Create the table legs]

    //! Table Leg
    auto tl1 = Ra::Core::Geometry::makeSharpBox({table_leg_side, table_leg_weight, table_leg_side});
    tl1.addAttrib("in_color", Ra::Core::Vector4Array {tl1.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tl1 = app.m_engine->getEntityManager()->createEntity( "Table leg 1" );
    Ra::Core::Transform transform_tl1( Ra::Core::Transform::Identity() );
    transform_tl1.translation() = Ra::Core::Vector3(table_width-cylinder_radius, -table_leg_weight, table_lenght-cylinder_radius);
    entity_tl1->setTransform(transform_tl1);
    entity_tl1->swapTransformBuffers();
    auto component_tl1 = new Ra::Engine::Scene::TriangleMeshComponent("Table leg 1 Mesh", entity_tl1, std::move(tl1), nullptr);

    auto tl2 = Ra::Core::Geometry::makeSharpBox({table_leg_side, table_leg_weight, table_leg_side});
    tl2.addAttrib("in_color", Ra::Core::Vector4Array {tl2.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tl2 = app.m_engine->getEntityManager()->createEntity( "Table leg 2" );
    Ra::Core::Transform transform_tl2( Ra::Core::Transform::Identity() );
    transform_tl2.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), -table_leg_weight, table_lenght-cylinder_radius);
    entity_tl2->setTransform(transform_tl2);
    entity_tl2->swapTransformBuffers();
    auto component_tl2 = new Ra::Engine::Scene::TriangleMeshComponent("Table leg 2 Mesh", entity_tl2, std::move(tl2), nullptr);

    auto tl3 = Ra::Core::Geometry::makeSharpBox({table_leg_side, table_leg_weight, table_leg_side});
    tl3.addAttrib("in_color", Ra::Core::Vector4Array {tl3.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tl3 = app.m_engine->getEntityManager()->createEntity( "Table leg 3" );
    Ra::Core::Transform transform_tl3( Ra::Core::Transform::Identity() );
    transform_tl3.translation() = Ra::Core::Vector3(table_width-cylinder_radius, -table_leg_weight, -(table_lenght-cylinder_radius));
    entity_tl3->setTransform(transform_tl3);
    entity_tl3->swapTransformBuffers();
    auto component_tl3 = new Ra::Engine::Scene::TriangleMeshComponent("Table leg 3 Mesh", entity_tl3, std::move(tl3), nullptr);

    auto tl4 = Ra::Core::Geometry::makeSharpBox({table_leg_side, table_leg_weight, table_leg_side});
    tl4.addAttrib("in_color", Ra::Core::Vector4Array {tl4.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tl4 = app.m_engine->getEntityManager()->createEntity( "Table leg 4" );
    Ra::Core::Transform transform_tl4( Ra::Core::Transform::Identity() );
    transform_tl4.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), -table_leg_weight, -(table_lenght-cylinder_radius));
    entity_tl4->setTransform(transform_tl4);
    entity_tl4->swapTransformBuffers();
    auto component_tl4 = new Ra::Engine::Scene::TriangleMeshComponent("Table leg 4 Mesh", entity_tl4, std::move(tl4), nullptr);



    //! Cylinder in Table Leg
    auto cylinder_in_table_leg = table_leg_side*1.25f;
    auto ctl1 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, 2.f*table_leg_weight, 0.f}, cylinder_in_table_leg, 32, Brown);
    Ra::Engine::Scene::Entity* entity_ctl1 = app.m_engine->getEntityManager()->createEntity( "Cylinder table leg 1" );
    Ra::Core::Transform transform_ctl1( Ra::Core::Transform::Identity() );
    transform_ctl1.translation() = Ra::Core::Vector3(table_width-cylinder_radius, -2.f*table_leg_weight, table_lenght-cylinder_radius);
    entity_ctl1->setTransform(transform_ctl1);
    entity_ctl1->swapTransformBuffers();
    auto component_ctl1 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder table leg 1 Mesh", entity_ctl1, std::move(ctl1), nullptr);

    auto ctl2 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, 2.f*table_leg_weight, 0.f}, cylinder_in_table_leg, 32, Brown);
    Ra::Engine::Scene::Entity* entity_ctl2 = app.m_engine->getEntityManager()->createEntity( "Cylinder table leg 2" );
    Ra::Core::Transform transform_ctl2( Ra::Core::Transform::Identity() );
    transform_ctl2.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), -2.f*table_leg_weight, table_lenght-cylinder_radius);
    entity_ctl2->setTransform(transform_ctl2);
    entity_ctl2->swapTransformBuffers();
    auto component_ctl2 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder table leg 2 Mesh", entity_ctl2, std::move(ctl2), nullptr);

    auto ctl3 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, 2.f*table_leg_weight, 0.f}, cylinder_in_table_leg, 32, Brown);
    Ra::Engine::Scene::Entity* entity_ctl3 = app.m_engine->getEntityManager()->createEntity( "Cylinder table leg 3" );
    Ra::Core::Transform transform_ctl3( Ra::Core::Transform::Identity() );
    transform_ctl3.translation() = Ra::Core::Vector3(table_width-cylinder_radius, -2.f*table_leg_weight, -(table_lenght-cylinder_radius));
    entity_ctl3->setTransform(transform_ctl3);
    entity_ctl3->swapTransformBuffers();
    auto component_ctl3 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder table leg 3 Mesh", entity_ctl3, std::move(ctl3), nullptr);

    auto ctl4 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, 2.f*table_leg_weight, 0.f}, cylinder_in_table_leg, 32, Brown);
    Ra::Engine::Scene::Entity* entity_ctl4 = app.m_engine->getEntityManager()->createEntity( "Cylinder table leg 4" );
    Ra::Core::Transform transform_ctl4( Ra::Core::Transform::Identity() );
    transform_ctl4.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), -2.f*table_leg_weight, -(table_lenght-cylinder_radius));
    entity_ctl4->setTransform(transform_ctl4);
    entity_ctl4->swapTransformBuffers();
    auto component_ctl4 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder table leg 4 Mesh", entity_ctl4, std::move(ctl4), nullptr);

    //! Cylinder Leg Up (between table leg and subtable)

    auto cl_up1 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, table_leg_weight, 0.f}, table_leg_side*1.5f, 32, Brown);
    Ra::Engine::Scene::Entity* entity_cl_up1 = app.m_engine->getEntityManager()->createEntity( "Cylinder Leg Up 1" );
    Ra::Core::Transform transform_cl_up1( Ra::Core::Transform::Identity() );
    transform_cl_up1.translation() = Ra::Core::Vector3((table_width-cylinder_radius), -table_leg_weight, (table_lenght-cylinder_radius));
    entity_cl_up1->setTransform(transform_cl_up1);
    entity_cl_up1->swapTransformBuffers();
    auto component_cl_up1 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder Leg Up 1 Mesh", entity_cl_up1, std::move(cl_up1), nullptr);

    auto cl_up2 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, table_leg_weight, 0.f}, table_leg_side*1.5f, 32, Brown);
    Ra::Engine::Scene::Entity* entity_cl_up2 = app.m_engine->getEntityManager()->createEntity( "Cylinder Leg Up 2" );
    Ra::Core::Transform transform_cl_up2( Ra::Core::Transform::Identity() );
    transform_cl_up2.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), -table_leg_weight, (table_lenght-cylinder_radius));
    entity_cl_up2->setTransform(transform_cl_up2);
    entity_cl_up2->swapTransformBuffers();
    auto component_cl_up2 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder Leg Up 2 Mesh", entity_cl_up2, std::move(cl_up2), nullptr);

    auto cl_up3 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, table_leg_weight, 0.f}, table_leg_side*1.5f, 32, Brown);
    Ra::Engine::Scene::Entity* entity_cl_up3 = app.m_engine->getEntityManager()->createEntity( "Cylinder Leg Up 3" );
    Ra::Core::Transform transform_cl_up3( Ra::Core::Transform::Identity() );
    transform_cl_up3.translation() = Ra::Core::Vector3((table_width-cylinder_radius), -table_leg_weight, -(table_lenght-cylinder_radius));
    entity_cl_up3->setTransform(transform_cl_up3);
    entity_cl_up3->swapTransformBuffers();
    auto component_cl_up3 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder Leg Up 3 Mesh", entity_cl_up3, std::move(cl_up3), nullptr);

    auto cl_up4 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, table_leg_weight, 0.f}, table_leg_side*1.5f, 32, Brown);
    Ra::Engine::Scene::Entity* entity_cl_up4 = app.m_engine->getEntityManager()->createEntity( "Cylinder Leg Up 4" );
    Ra::Core::Transform transform_cl_up4( Ra::Core::Transform::Identity() );
    transform_cl_up4.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), -table_leg_weight, -(table_lenght-cylinder_radius));
    entity_cl_up4->setTransform(transform_cl_up4);
    entity_cl_up4->swapTransformBuffers();
    auto component_cl_up4 = new Ra::Engine::Scene::TriangleMeshComponent("Cylinder Leg Up 4 Mesh", entity_cl_up4, std::move(cl_up4), nullptr);

    //! Table Leg Side (between legs)

        //! length side
    auto tls1 = Ra::Core::Geometry::makeSharpBox({border_cylinder_thickness, 0.5f*table_leg_weight, table_lenght-cylinder_radius});
    tls1.addAttrib("in_color", Ra::Core::Vector4Array {tls1.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tls1 = app.m_engine->getEntityManager()->createEntity( "Table Leg Side 1" );
    Ra::Core::Transform transform_tls1( Ra::Core::Transform::Identity() );
    transform_tls1.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), -0.5f*table_leg_weight, 0.f);
    entity_tls1->setTransform(transform_tls1);
    entity_tls1->swapTransformBuffers();
    auto component_tls1 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Side 1 Mesh", entity_tls1, std::move(tls1), nullptr);

    auto tls2 = Ra::Core::Geometry::makeSharpBox({border_cylinder_thickness, 0.5f*table_leg_weight, table_lenght-cylinder_radius});
    tls2.addAttrib("in_color", Ra::Core::Vector4Array {tls2.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tls2 = app.m_engine->getEntityManager()->createEntity( "Table Leg Side 2" );
    Ra::Core::Transform transform_tls2( Ra::Core::Transform::Identity() );
    transform_tls2.translation() = Ra::Core::Vector3((table_width-cylinder_radius), -0.5f*table_leg_weight, 0.f);
    entity_tls2->setTransform(transform_tls2);
    entity_tls2->swapTransformBuffers();
    auto component_tls2 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Side 2 Mesh", entity_tls2, std::move(tls2), nullptr);

        //! width side
    auto tls3 = Ra::Core::Geometry::makeSharpBox({table_width-cylinder_radius, 0.5f*table_leg_weight, border_cylinder_thickness});
    tls3.addAttrib("in_color", Ra::Core::Vector4Array {tls3.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tls3 = app.m_engine->getEntityManager()->createEntity( "Table Leg Side 3" );
    Ra::Core::Transform transform_tls3( Ra::Core::Transform::Identity() );
    transform_tls3.translation() = Ra::Core::Vector3(0.f, -0.5f*table_leg_weight, -(table_lenght-cylinder_radius));
    entity_tls3->setTransform(transform_tls3);
    entity_tls3->swapTransformBuffers();
    auto component_tls3 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Side 3 Mesh", entity_tls3, std::move(tls3), nullptr);

    auto tls4 = Ra::Core::Geometry::makeSharpBox({table_width-cylinder_radius, 0.5f*table_leg_weight, border_cylinder_thickness});
    tls4.addAttrib("in_color", Ra::Core::Vector4Array {tls4.vertices().size(), Brown});
    Ra::Engine::Scene::Entity* entity_tls4 = app.m_engine->getEntityManager()->createEntity( "Table Leg Side 4" );
    Ra::Core::Transform transform_tls4( Ra::Core::Transform::Identity() );
    transform_tls4.translation() = Ra::Core::Vector3(0.f, -0.5f*table_leg_weight, (table_lenght-cylinder_radius));
    entity_tls4->setTransform(transform_tls4);
    entity_tls4->swapTransformBuffers();
    auto component_tls4 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Side 4 Mesh", entity_tls4, std::move(tls4), nullptr);

    //! Table Leg Foot Box (above legs)

    auto table_leg_foot_box_lenght = cylinder_in_table_leg+0.02f;
    auto tlfb_thickness = border_cylinder_thickness;
    auto tlfb_height = -2.f*table_leg_weight;

    auto tlfb1 = Ra::Core::Geometry::makeSharpBox({table_leg_foot_box_lenght, tlfb_thickness, table_leg_foot_box_lenght});
    tlfb1.addAttrib("in_color", Ra::Core::Vector4Array {tlfb1.vertices().size(), Ra::Core::Utils::Color::Grey()});
    Ra::Engine::Scene::Entity* entity_tlfb1 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Box 1" );
    Ra::Core::Transform transform_tlfb1( Ra::Core::Transform::Identity() );
    transform_tlfb1.translation() = Ra::Core::Vector3((table_width-cylinder_radius), tlfb_height, (table_lenght-cylinder_radius));
    entity_tlfb1->setTransform(transform_tlfb1);
    entity_tlfb1->swapTransformBuffers();
    auto component_tlfb1 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Box 1 Mesh", entity_tlfb1, std::move(tlfb1), nullptr);

    auto tlfb2 = Ra::Core::Geometry::makeSharpBox({table_leg_foot_box_lenght, tlfb_thickness, table_leg_foot_box_lenght});
    tlfb2.addAttrib("in_color", Ra::Core::Vector4Array {tlfb2.vertices().size(), Ra::Core::Utils::Color::Grey()});
    Ra::Engine::Scene::Entity* entity_tlfb2 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Box 2" );
    Ra::Core::Transform transform_tlfb2( Ra::Core::Transform::Identity() );
    transform_tlfb2.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), tlfb_height, (table_lenght-cylinder_radius));
    entity_tlfb2->setTransform(transform_tlfb2);
    entity_tlfb2->swapTransformBuffers();
    auto component_tlfb2 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Box 2 Mesh", entity_tlfb2, std::move(tlfb2), nullptr);

    auto tlfb3 = Ra::Core::Geometry::makeSharpBox({table_leg_foot_box_lenght, tlfb_thickness, table_leg_foot_box_lenght});
    tlfb3.addAttrib("in_color", Ra::Core::Vector4Array {tlfb3.vertices().size(), Ra::Core::Utils::Color::Grey()});
    Ra::Engine::Scene::Entity* entity_tlfb3 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Box 3" );
    Ra::Core::Transform transform_tlfb3( Ra::Core::Transform::Identity() );
    transform_tlfb3.translation() = Ra::Core::Vector3((table_width-cylinder_radius), tlfb_height, -(table_lenght-cylinder_radius));
    entity_tlfb3->setTransform(transform_tlfb3);
    entity_tlfb3->swapTransformBuffers();
    auto component_tlfb3 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Box 3 Mesh", entity_tlfb3, std::move(tlfb3), nullptr);

    auto tlfb4 = Ra::Core::Geometry::makeSharpBox({table_leg_foot_box_lenght, tlfb_thickness, table_leg_foot_box_lenght});
    tlfb4.addAttrib("in_color", Ra::Core::Vector4Array {tlfb4.vertices().size(), Ra::Core::Utils::Color::Grey()});
    Ra::Engine::Scene::Entity* entity_tlfb4 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Box 4" );
    Ra::Core::Transform transform_tlfb4( Ra::Core::Transform::Identity() );
    transform_tlfb4.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), tlfb_height, -(table_lenght-cylinder_radius));
    entity_tlfb4->setTransform(transform_tlfb4);
    entity_tlfb4->swapTransformBuffers();
    auto component_tlfb4 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Box 4 Mesh", entity_tlfb4, std::move(tlfb4), nullptr);

    //! Table Leg Foot Cylinder (above legs)
    auto tlfc_thickness = tlfb_thickness;
    auto tlfc_height = tlfb_height - 2.f*tlfb_thickness;
    auto tlfc_radius = table_leg_foot_box_lenght + 0.1f;

    auto tlfc1 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, tlfc_thickness, 0.f}, tlfc_radius, 32, Grey);
    Ra::Engine::Scene::Entity* entity_tlfc1 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Cylinder 1" );
    Ra::Core::Transform transform_tlfc1( Ra::Core::Transform::Identity() );
    transform_tlfc1.translation() = Ra::Core::Vector3((table_width-cylinder_radius), tlfc_height, (table_lenght-cylinder_radius));
    entity_tlfc1->setTransform(transform_tlfc1);
    entity_tlfc1->swapTransformBuffers();
    auto component_tlfc1 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Cylinder 1 Mesh", entity_tlfc1, std::move(tlfc1), nullptr);

    auto tlfc2 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, tlfc_thickness, 0.f}, tlfc_radius, 32, Grey);
    Ra::Engine::Scene::Entity* entity_tlfc2 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Cylinder 2" );
    Ra::Core::Transform transform_tlfc2( Ra::Core::Transform::Identity() );
    transform_tlfc2.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), tlfc_height, (table_lenght-cylinder_radius));
    entity_tlfc2->setTransform(transform_tlfc2);
    entity_tlfc2->swapTransformBuffers();
    auto component_tlfc2 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Cylinder 2 Mesh", entity_tlfc2, std::move(tlfc2), nullptr);

    auto tlfc3 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, tlfc_thickness, 0.f}, tlfc_radius, 32, Grey);
    Ra::Engine::Scene::Entity* entity_tlfc3 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Cylinder 3" );
    Ra::Core::Transform transform_tlfc3( Ra::Core::Transform::Identity() );
    transform_tlfc3.translation() = Ra::Core::Vector3((table_width-cylinder_radius), tlfc_height, -(table_lenght-cylinder_radius));
    entity_tlfc3->setTransform(transform_tlfc3);
    entity_tlfc3->swapTransformBuffers();
    auto component_tlfc3 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Cylinder 3 Mesh", entity_tlfc3, std::move(tlfc3), nullptr);

    auto tlfc4 = Ra::Core::Geometry::makeCylinder({0.f,0.f,0.f}, {0.f, tlfc_thickness, 0.f}, tlfc_radius, 32, Grey);
    Ra::Engine::Scene::Entity* entity_tlfc4 = app.m_engine->getEntityManager()->createEntity( "Table Leg Foot Cylinder 4" );
    Ra::Core::Transform transform_tlfc4( Ra::Core::Transform::Identity() );
    transform_tlfc4.translation() = Ra::Core::Vector3(-(table_width-cylinder_radius), tlfc_height, -(table_lenght-cylinder_radius));
    entity_tlfc4->setTransform(transform_tlfc4);
    entity_tlfc4->swapTransformBuffers();
    auto component_tlfc4 = new Ra::Engine::Scene::TriangleMeshComponent("Table Leg Foot Cylinder 4 Mesh", entity_tlfc4, std::move(tlfc4), nullptr);


    //! [Create a geometry component with the balls]
    auto ball_radius = 0.075f;
    auto ball_height = ball_radius+thickness;
    auto ball_zone_width = table_width-(border_cylinder_height+border_cylinder_thickness);
    auto ball_zone_lenght = table_lenght-(border_cylinder_height+border_cylinder_thickness);

    auto ball0 = Ra::Core::Geometry::makeParametricSphere(ball_radius, Ra::Core::Utils::Color::White());
    Ra::Engine::Scene::Entity* entity_ball0 = app.m_engine->getEntityManager()->createEntity( "Ball white" );
    Ra::Core::Transform transform_ball0( Ra::Core::Transform::Identity() );
    transform_ball0.translation() = Ra::Core::Vector3(0.f, ball_height, 0.f);
    entity_ball0->setTransform(transform_ball0);
    entity_ball0->swapTransformBuffers();
    auto component_ball0 = new Ra::Engine::Scene::TriangleMeshComponent("Ball white Mesh", entity_ball0, std::move(ball0), nullptr);

    auto ball1 = Ra::Core::Geometry::makeParametricSphere(ball_radius, Ra::Core::Utils::Color::Red());
    Ra::Engine::Scene::Entity* entity_ball1 = app.m_engine->getEntityManager()->createEntity( "Ball red" );
    Ra::Core::Transform transform_ball1( Ra::Core::Transform::Identity() );
    transform_ball1.translation() = Ra::Core::Vector3(-0.9f*ball_zone_width, ball_height, -0.8f*ball_zone_lenght);
    entity_ball1->setTransform(transform_ball1);
    entity_ball1->swapTransformBuffers();
    auto component_ball1 = new Ra::Engine::Scene::TriangleMeshComponent("Ball red Mesh", entity_ball1, std::move(ball1), nullptr);

    auto ball2 = Ra::Core::Geometry::makeParametricSphere(ball_radius, Ra::Core::Utils::Color::Yellow());
    Ra::Engine::Scene::Entity* entity_ball2 = app.m_engine->getEntityManager()->createEntity( "Ball yellow" );
    Ra::Core::Transform transform_ball2( Ra::Core::Transform::Identity() );
    transform_ball2.translation() = Ra::Core::Vector3(-0.5f*ball_zone_width, ball_height, -0.9f*ball_zone_lenght);
    entity_ball2->setTransform(transform_ball2);
    entity_ball2->swapTransformBuffers();
    auto component_ball2 = new Ra::Engine::Scene::TriangleMeshComponent("Ball yellow Mesh", entity_ball2, std::move(ball2), nullptr);


    auto ball3 = Ra::Core::Geometry::makeParametricSphere(ball_radius, Ra::Core::Utils::Color::Blue());
    Ra::Engine::Scene::Entity* entity_ball3 = app.m_engine->getEntityManager()->createEntity( "Ball blue" );
    Ra::Core::Transform transform_ball3( Ra::Core::Transform::Identity() );
    transform_ball3.translation() = Ra::Core::Vector3(0.14f*ball_zone_width, ball_height, 0.45f*ball_zone_lenght);
    entity_ball3->setTransform(transform_ball3);
    entity_ball3->swapTransformBuffers();
    auto component_ball3 = new Ra::Engine::Scene::TriangleMeshComponent("Ball blue Mesh", entity_ball3, std::move(ball3), nullptr);



    /*//! [Register the entity/component association to the geometry system ]
    auto geometrySystem = app.m_engine->getSystem( "GeometrySystem" );

    //! [Add green plane]
    geometrySystem->addComponent(entity_table, component_table);

    //! [Add black cylinders ]
    geometrySystem->addComponent(entity_c1, component_c1);
    geometrySystem->addComponent(entity_c2, component_c2);
    geometrySystem->addComponent(entity_c3, component_c3);
    geometrySystem->addComponent(entity_c4, component_c4);
    geometrySystem->addComponent(entity_c5, component_c5);
    geometrySystem->addComponent(entity_c6, component_c6);

    //! [Add border]
    geometrySystem->addComponent(entity_b1, component_b1);
    geometrySystem->addComponent(entity_b2, component_b2);
    geometrySystem->addComponent(entity_b3, component_b3);
    geometrySystem->addComponent(entity_b4, component_b4);
    geometrySystem->addComponent(entity_b5, component_b5);
    geometrySystem->addComponent(entity_b6, component_b6);

    //! Add subtable
    geometrySystem->addComponent(entity_subtable, component_subtable);

    //! Add boarders cylinder
    geometrySystem->addComponent(entity_bc1, component_bc1);
    geometrySystem->addComponent(entity_bc2, component_bc2);
    geometrySystem->addComponent(entity_bc3, component_bc3);
    geometrySystem->addComponent(entity_bc4, component_bc4);

    //! Add Table Leg
    geometrySystem->addComponent(entity_tl1, component_tl1);
    geometrySystem->addComponent(entity_tl2, component_tl2);
    geometrySystem->addComponent(entity_tl3, component_tl3);
    geometrySystem->addComponent(entity_tl4, component_tl4);

    //! Add Cylinder in Table Leg
    geometrySystem->addComponent(entity_ctl1, component_ctl1);
    geometrySystem->addComponent(entity_ctl2, component_ctl2);
    geometrySystem->addComponent(entity_ctl3, component_ctl3);
    geometrySystem->addComponent(entity_ctl4, component_ctl4);

    //! Add Cylinder Leg Up (between table leg and subtable)
    geometrySystem->addComponent(entity_cl_up1, component_cl_up1);
    geometrySystem->addComponent(entity_cl_up2, component_cl_up2);
    geometrySystem->addComponent(entity_cl_up3, component_cl_up3);
    geometrySystem->addComponent(entity_cl_up4, component_cl_up4);

    //! Add Table Leg Side (between legs)
    geometrySystem->addComponent(entity_tls1, component_tls1);
    geometrySystem->addComponent(entity_tls2, component_tls2);
    geometrySystem->addComponent(entity_tls3, component_tls3);
    geometrySystem->addComponent(entity_tls4, component_tls4);

    //! Add Table Leg Foot Box (above legs)
    geometrySystem->addComponent(entity_tlfb1, component_tlfb1);
    geometrySystem->addComponent(entity_tlfb2, component_tlfb2);
    geometrySystem->addComponent(entity_tlfb3, component_tlfb3);
    geometrySystem->addComponent(entity_tlfb4, component_tlfb4);

    //! Add Table Leg Foot Cylinder (above legs)
    geometrySystem->addComponent(entity_tlfc1, component_tlfc1);
    geometrySystem->addComponent(entity_tlfc2, component_tlfc2);
    geometrySystem->addComponent(entity_tlfc3, component_tlfc3);
    geometrySystem->addComponent(entity_tlfc4, component_tlfc4);

    //! [Add sphere]
    //geometrySystem->addComponent(entity_ball0, component_ball0);
    geometrySystem->addComponent(entity_ball1, component_ball1);
    geometrySystem->addComponent(entity_ball2, component_ball2);
    geometrySystem->addComponent(entity_ball3, component_ball3);*/





    //! [Tell the window that something is to be displayed]
    app.m_mainWindow->prepareDisplay();

    app.setContinuousUpdate(false);
    return MainApplication::exec();

}

